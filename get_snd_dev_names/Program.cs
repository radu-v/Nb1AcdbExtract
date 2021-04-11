using System;
using System.IO;
using System.Text;
using AcdbData;
using ELFSharp.ELF;
using ELFSharp.ELF.Sections;

namespace get_snd_dev_names
{
   class Program
   {
      static void Main(string[] args)
      {
         const string halPath = @"audio.primary.msm8998.so";

         var elf = ELFReader.Load(halPath);

         if (elf.GetSection(".data.rel.ro") is not Section<ulong> dataRelRoSection)
         {
            Console.WriteLine(".data.rel.ro section not found.");
            return;
         }

         if (elf.GetSection(".rodata") is not Section<ulong> rodataSection)
         {
            Console.WriteLine(".rodata section not found.");
            return;
         }

         if (elf.GetSection(".data") is not Section<ulong> dataSection)
         {
            Console.WriteLine(".data section not found.");
            return;
         }

         DumpDeviceTable(dataRelRoSection.GetContents(), dataRelRoSection.LoadAddress,
            rodataSection.LoadAddress, rodataSection.GetContents().AsSpan());
         DumpAcdbIdsTable(dataSection.GetContents(), dataSection.LoadAddress);
      }

      static void DumpDeviceTable(byte[] dataRelRoSection, ulong dataSectionLoadAddress, ulong rodataSectionLoadAddress,
         Span<byte> rodataSection)
      {
         const int deviceTableAddress = 0x8df88;
         var offsetDelta = deviceTableAddress - dataSectionLoadAddress;
         
         using var deviceTableFile = new StreamWriter("device_table.h");
         deviceTableFile.WriteLine(@"static char * device_table[SND_DEVICE_MAX] = {");

         foreach (var i in Enum.GetValues<AcdbDevices>())
         {
            if (i == AcdbDevices.SND_DEVICE_MAX) continue;

            var entryPointer = BitConverter.ToUInt64(dataRelRoSection, (int) offsetDelta + (int) i * 8);

            if (entryPointer == 0)
            {
               deviceTableFile.WriteLine($"\t[{AcdbData.AcdbData.FauxDeviceTable[i]}] = \"\",");
               continue;
            }

            var entryOffsetDelta = entryPointer - rodataSectionLoadAddress;
            var slice = rodataSection[(int) entryOffsetDelta..];
            var nullTerminatorIndex = slice.IndexOf((byte) 0);
            slice = slice[..nullTerminatorIndex];
            var entry = Encoding.ASCII.GetString(slice);

            deviceTableFile.WriteLine(AcdbData.AcdbData.FauxDeviceTable.TryGetValue(i, out var name)
               ? $"\t[{name}] = \"{entry}\","
               : $" /* error getting name for {i} */");
         }

         deviceTableFile.WriteLine("};");
      }
      
      static void DumpAcdbIdsTable(byte[] dataSection, ulong dataSectionLoadAddress)
      {
         const int acdbIdsTableAddress = 0x90420;
         var offsetDelta = acdbIdsTableAddress - dataSectionLoadAddress;
         
         using var deviceTableFile = new StreamWriter("acdb_ids.h");
         deviceTableFile.WriteLine(@"static int acdb_device_table[SND_DEVICE_MAX] = {");

         foreach (var i in Enum.GetValues<AcdbDevices>())
         {
            if (i == AcdbDevices.SND_DEVICE_MAX) continue;

            var acdbId = BitConverter.ToInt32(dataSection, (int) offsetDelta + (int) i * 4);

            deviceTableFile.WriteLine(AcdbData.AcdbData.FauxDeviceTable.TryGetValue(i, out var name)
               ? $"\t[{name}] = {acdbId},"
               : $" /* error getting name for {i} */");
         }

         deviceTableFile.WriteLine("};");
      }
   }
}