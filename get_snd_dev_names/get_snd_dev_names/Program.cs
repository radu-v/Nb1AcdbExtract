using System;
using System.Text;
using ELFSharp.ELF;
using ELFSharp.ELF.Sections;
using static get_snd_dev_names.AcdbData;

namespace get_snd_dev_names
{
   class Program
   {
      static void Main(string[] args)
      {
         const string halPath = @"audio.primary.msm8998.so";
         const int operatorSpecificDeviceTablAddress = 0x8df88;

         var elf = ELFReader.Load(halPath);

         if (!(elf.GetSection(".data.rel.ro") is Section<ulong> dataSection))
         {
            Console.WriteLine(".data.rel.ro section not found.");
            return;
         }

         if (!(elf.GetSection(".rodata") is Section<ulong> rodataSection))
         {
            Console.WriteLine(".rodata section not found.");
            return;
         }

         var dataRelRo = dataSection.GetContents();
         var rodata = rodataSection.GetContents().AsSpan();
         var offsetDelta = operatorSpecificDeviceTablAddress - dataSection.LoadAddress;

         Console.WriteLine("static char * device_table[SND_DEVICE_MAX] = {");
         
         for (var i = AcdbDevices.SND_DEVICE_NONE; i < AcdbDevices.SND_DEVICE_MAX; i++)
         {
            var entryPointer = BitConverter.ToUInt64(dataRelRo, (int) offsetDelta + (int)i * 8);

            if (entryPointer == 0)
            {
               Console.WriteLine($"\t[{FauxDeviceTable[i]}] = \"\",");
               continue;
            }
            
            var entryOffsetDelta = entryPointer - rodataSection.LoadAddress;
            var slice = rodata.Slice((int) entryOffsetDelta);
            var nullTerminatorIndex = slice.IndexOf((byte) 0);
            slice = slice.Slice(0, nullTerminatorIndex);
            var entry = Encoding.ASCII.GetString(slice);

            Console.WriteLine($"\t[{FauxDeviceTable[i]}] = \"{entry}\",");
         }
         
         Console.WriteLine("};");
      }
   }
}