using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace AcdbExtract
{
    class Program
    {
        public static void Main(string[] args)
        {
            var path = args[0];
            var sndDevice = Encoding.UTF8.GetBytes("\0SND_DEVICE_");

            var fileSize = new FileInfo(path).Length;
            using var stream = File.Open(path, FileMode.Open);
            using var binaryReader = new BinaryReader(stream);
            var bytes = binaryReader.ReadBytes((int) fileSize);
            var fileSpan = bytes.AsSpan();
            var startOffset = fileSpan.IndexOf(sndDevice) + 1;

            var idDevName = new List<(int id, string name)>();

            while (startOffset > 0)
            {
                var slice = fileSpan.Slice(startOffset, 100);
                slice = slice[..slice.IndexOf(Convert.ToByte(0))];

                if (slice.IsEmpty)
                    break;

                var devName = Encoding.ASCII.GetString(slice);
                var idSpan = fileSpan.Slice(startOffset + 100, 4);
                idSpan.Reverse();
                var id = (idSpan[0] << 24) | (idSpan[1] << 16) | (idSpan[2] << 8) | (idSpan[3]);

                idDevName.Add((id, devName));

                startOffset += 104;
            }

            var groups = idDevName
                .OrderBy(x => x.id)
                .GroupBy(x => x.id, x => x.name)
                .ToList();
            
            DumpEnum(groups);
            DumpFauxDeviceTable(groups);
        }

        static void DumpFauxDeviceTable(IEnumerable<IGrouping<int, string>> groups)
        {
            using var fauxDeviceTable = new StreamWriter("FauxDeviceTable.cs");
            fauxDeviceTable.WriteLine(@"using System.Collections.Generic;
namespace AcdbData
{
    public static class AcdbData
    {
        public static readonly Dictionary<AcdbDevices, string> FauxDeviceTable = new()
        {
            [AcdbDevices.SND_DEVICE_NONE] = ""SND_DEVICE_NONE"",");

            foreach (var group in groups)
            {
                foreach (var name in group.Distinct())
                {
                    fauxDeviceTable.WriteLine($"            [AcdbDevices.{name}] = \"{name}\",");
                }
            }

            fauxDeviceTable.WriteLine(@"        };
    }
}");
        }

        static void DumpEnum(IEnumerable<IGrouping<int, string>> groups)
        {
            using var enumFile = new StreamWriter("AcdbDevices.cs");
            enumFile.WriteLine(@"namespace AcdbData
{
    public enum AcdbDevices : int
    {
        SND_DEVICE_NONE = 0,");

            foreach (var group in groups)
            {
                foreach (var name in group.Distinct())
                {
                    enumFile.WriteLine($"        {name} = {@group.Key},");
                }
            }

            enumFile.WriteLine(@"        SND_DEVICE_MAX,
    };
}");
            enumFile.Flush();
        }
    }
}