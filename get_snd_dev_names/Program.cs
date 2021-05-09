using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using ELFSharp.ELF;
using ELFSharp.ELF.Sections;

namespace get_snd_dev_names
{
   class Program
   {
      const string HalPath = @"audio.primary.msm8998.so";

      // ReSharper disable InconsistentNaming
      static readonly (ulong offset, int size) device_table = (0x8df88, 1440);
      static readonly (ulong offset, int size) cal_name_info = (0x9031c, 80);
      static readonly (ulong offset, int size) dsp_only_decoders_mime = (0x9036c, 180);
      static readonly (ulong offset, int size) acdb_device_table = (0x90420, 720);
      static readonly (ulong offset, int size) pcm_device_table = (0x906f0, 504);
      static readonly (ulong offset, int size) snd_device_name_index = (0x908e8, 18616);
      static readonly (ulong offset, int size) usecase_name_index = (0x95208, 0);

      static void Main(string[] args)
      {
         var elf = ELFReader.Load(HalPath);

         Section<ulong> section;

         var sndDevices = ExtractSndDeviceNameIndex(elf);
         var usecaseNames = ExtractUsecaseNameIndex(elf);
         ExtractDeviceTable(elf, sndDevices);
         ExtractCalNameInfo(elf);
         ExtractDspOnlyDecodersMime(elf);
         ExtractAcdbDeviceTable(elf, sndDevices);
         ExtractPcmDeviceTable(elf, usecaseNames);
      }

      static Dictionary<int, string> ExtractUsecaseNameIndex(IELF elf)
      {
         var section = GetSectionByAddress(elf, usecase_name_index.offset);
         var offsetDelta = (int) (usecase_name_index.offset - section.LoadAddress);
         var data = section.GetContents().AsSpan()[offsetDelta..];

         using var file = new StreamWriter("usecase_name_index.h");
         file.WriteLine("#include \"usecase_enum.h\"\n");
         file.WriteLine(@"static struct name_to_index usecase_name_index[AUDIO_USECASE_MAX] = {");

         var usecaseNames = new Dictionary<string, int>();

         for (var row = 0;; row++)
         {
            var nameSlice = data.Slice(row * 104, 100);
            var name = ToAsciiZ(nameSlice);
            if (string.IsNullOrEmpty(name)) break;

            var index = BitConverter.ToInt32(data.Slice(row * 104 + 100, 4).ToArray());
            file.WriteLine($"\t{{TO_NAME_INDEX({name})}}, /* {{\"{name}\", {index}}} */");

            usecaseNames[name] = index;
         }

         file.WriteLine("};");

         using var usecaseEnum = new StreamWriter("usecase_enum.h");
         usecaseEnum.WriteLine("enum {");
         usecaseEnum.WriteLine("\tUSECASE_INVALID = -1,");

         foreach (var (key, value) in usecaseNames.OrderBy(x => x.Value))
         {
            usecaseEnum.WriteLine($"\t{key} = {value},");
         }

         usecaseEnum.WriteLine("\tAUDIO_USECASE_MAX");
         usecaseEnum.WriteLine("};");

         return usecaseNames.OrderBy(k => k.Value).ToDictionary(k => k.Value, v => v.Key);
      }

      static Dictionary<int, string> ExtractSndDeviceNameIndex(IELF elf)
      {
         var section = GetSectionByAddress(elf, snd_device_name_index.offset);
         var offsetDelta = (int) (snd_device_name_index.offset - section.LoadAddress);
         var data = section.GetContents().AsSpan().Slice(offsetDelta, snd_device_name_index.size);

         using var file = new StreamWriter("snd_device_name_index.h");
         file.WriteLine("#include \"snd_device_enum.h\"\n");
         file.WriteLine(@"static struct name_to_index snd_device_name_index[SND_DEVICE_MAX] = {");

         var deviceNames = new Dictionary<string, int> {["SND_DEVICE_NONE"] = 0};

         for (var row = 0; row < 179; row++)
         {
            var nameSlice = data.Slice(row * 104, 100);
            var name = ToAsciiZ(nameSlice);
            if (string.IsNullOrEmpty(name)) continue;

            var index = BitConverter.ToInt32(data.Slice(row * 104 + 100, 4).ToArray());
            file.WriteLine($"\t{{TO_NAME_INDEX({name})}}, /* {{\"{name}\", {index}}} */");

            deviceNames[name] = index;
         }

         file.WriteLine("};");

         using var sndDevicesEnum = new StreamWriter("snd_device_enum.h");
         sndDevicesEnum.WriteLine("enum {");

         foreach (var (key, value) in deviceNames.OrderBy(x => x.Value))
         {
            sndDevicesEnum.WriteLine($"\t{key} = {value},");
         }

         sndDevicesEnum.WriteLine("\tSND_DEVICE_MAX");
         sndDevicesEnum.WriteLine("};");

         return deviceNames.OrderBy(k => k.Value).ToDictionary(k => k.Value, v => v.Key);
      }

      static void ExtractPcmDeviceTable(IELF elf, IReadOnlyDictionary<int, string> usecaseNames)
      {
         var section = GetSectionByAddress(elf, pcm_device_table.offset);
         var offsetDelta = (int) (pcm_device_table.offset - section.LoadAddress);
         var data = section.GetContents().AsSpan().Slice(offsetDelta, pcm_device_table.size);

         using var file = new StreamWriter("pcm_device_table.h");
         file.WriteLine("#include \"snd_device_enum.h\"\n");
         file.WriteLine(@"static int pcm_device_table[AUDIO_USECASE_MAX][2] = {");

         for (var i = 0; i < 63; i++)
         {
            var dev1 = BitConverter.ToInt32(data.Slice(i * 8, 4).ToArray());
            var dev2 = BitConverter.ToInt32(data.Slice(i * 8 + 4, 4).ToArray());

            file.WriteLine(usecaseNames.TryGetValue(i, out var usecase)
               ? $"\t[{usecase}] = {{{dev1}, {dev2}}},"
               : $"\t[{i.ToString()}] = {{{dev1}, {dev2}}}, /* unknown usecase index */");
         }

         file.WriteLine("};");
      }

      static void ExtractAcdbDeviceTable(IELF elf, Dictionary<int, string> sndDevices)
      {
         var section = GetSectionByAddress(elf, acdb_device_table.offset);
         var offsetDelta = (int) (acdb_device_table.offset - section.LoadAddress);
         var data = section.GetContents().AsSpan().Slice(offsetDelta, acdb_device_table.size);

         using var file = new StreamWriter("acdb_device_table.h");
         file.WriteLine("#include \"snd_device_enum.h\"\n");
         file.WriteLine(@"static const int acdb_device_table[SND_DEVICE_MAX] = {");

         foreach (var (key, value) in sndDevices)
         {
            var acdbId = BitConverter.ToInt32(data.Slice(key * 4, 4).ToArray());
            file.WriteLine($"\t[{value}] = {acdbId},");
         }

         file.WriteLine("};");
      }

      static void ExtractDspOnlyDecodersMime(IELF elf)
      {
         var section = GetSectionByAddress(elf, dsp_only_decoders_mime.offset);
         var offsetDelta = (int) (dsp_only_decoders_mime.offset - section.LoadAddress);
         var data = section.GetContents().AsSpan().Slice(offsetDelta, dsp_only_decoders_mime.size);

         using var file = new StreamWriter("dsp_only_decoders_mime.h");
         file.WriteLine(@"char dsp_only_decoders_mime[][30] = {");

         for (var row = 0; row < 6; row++)
         {
            var slice = data.Slice(row * 30, 30);
            var entry = ToAsciiZ(slice);
            file.WriteLine($"\t[{row}] = \"{entry}\",");
         }

         file.WriteLine("};");
      }

      static void ExtractCalNameInfo(IELF elf)
      {
         var section = GetSectionByAddress(elf, cal_name_info.offset);
         var offsetDelta = (int) (cal_name_info.offset - section.LoadAddress);
         var data = section.GetContents().AsSpan().Slice(offsetDelta, cal_name_info.size);

         using var file = new StreamWriter("cal_name_info.h");
         file.WriteLine(@"char cal_name_info[4][20] = {");

         for (var row = 0; row < 4; row++)
         {
            var slice = data.Slice(row * 20, 20);
            var entry = ToAsciiZ(slice);
            file.WriteLine($"\t[{row}] = \"{entry}\",");
         }

         file.WriteLine("};");
      }

      static void ExtractDeviceTable(IELF elf, IReadOnlyDictionary<int, string> sndDevices)
      {
         var section = GetSectionByAddress(elf, device_table.offset);
         var offsetDelta = (int) (device_table.offset - section.LoadAddress);
         var data = section.GetContents().AsSpan().Slice(offsetDelta, device_table.size);

         using var file = new StreamWriter("device_table.h");
         file.WriteLine("#include \"snd_device_enum.h\"\n");
         file.WriteLine(@"static const char * const device_table[SND_DEVICE_MAX] = {");

         Section<ulong> dataSection = null;
         Span<byte> dataSectionSpan = default;

         for (var row = 0; row < 180; row++)
         {
            var haveSndDeviceName = sndDevices.TryGetValue(row, out var sndDeviceName);
            var nameOffset = BitConverter.ToUInt64(data.Slice(row * 8, 8));

            if (nameOffset == 0)
            {
               file.WriteLine($"\t/* no name for {(haveSndDeviceName ? sndDeviceName : row)} */");
               continue;
            }

            if (dataSection == null)
            {
               dataSection = GetSectionByAddress(elf, nameOffset);
               dataSectionSpan = dataSection.GetContents();
            }

            var slice = dataSectionSpan[(int)(nameOffset - dataSection.LoadAddress)..];
            var entry = ToAsciiZ(slice);

            file.WriteLine(haveSndDeviceName
               ? $"\t[{sndDeviceName}] = \"{entry}\","
               : $"\t[{row}] = \"{entry}\", /* unknown SND_DEVICE_ */");
         }

         file.WriteLine("};");
      }

      static string ToAsciiZ(Span<byte> slice) => Encoding.ASCII.GetString(slice[..slice.IndexOf((byte) 0)]);

      static Section<ulong> GetSectionByAddress(IELF elf, ulong address)
      {
         var section = elf.Sections
            .OfType<Section<ulong>>()
            .FirstOrDefault(x =>
               x.LoadAddress <= address && address < (x.LoadAddress + x.Size));

         if (section == null)
            throw new ArgumentOutOfRangeException(nameof(address),
               $"Could not find a section for address {address:x8}");

         return section;
      }
   }
}