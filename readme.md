These are a hacky couple of apps for extracting ACDB IDs from the stock 515K
Nokia 8 ROM.

The offsets to `device_table` and `acdb_device_table` are hardcoded 

1. compile and run AcdbExtract with the path to audio HAL .so as a parameter
2. copy the generated `AcdbDevices.cs` and `AcdbDevices.csFauxDeviceTable.cs` to
the `get_snd_dev_names` project, build it and run it.
3. use the generated `device_table.h` and `acdb_ids.h` to your needs
