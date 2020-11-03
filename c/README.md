# A simple C program with two sensors

This is the simple and modified example which can read two ds18b20 sensors attached to the Rasberry Pi through sysfs. The original code is located in the [1] site.


## DS18B20

I bought the IZOKEE 5 Pack DS18B20 Temperature Sensor Digital Thermal Stainless Steel Tube at Amazon. That is the most cheapest one which I've found. And two sensors are used for this demo.

## Build

```bash
$ make
$ sudo ./1WireBin 
 rom[0]: 28-0301a279e7d9
 rom[1]: 28-3c01d6079a0d
>> Mon Nov  2 22:03:42 2020
>>        0 Sensor 28-0301a279e7d9 temperature [0] : 28.500 °C
>>        0 Sensor 28-3c01d6079a0d temperature [1] : 25.125 °C
>> Mon Nov  2 22:03:44 2020
>>        1 Sensor 28-0301a279e7d9 temperature [0] : 28.500 °C
>>        1 Sensor 28-3c01d6079a0d temperature [1] : 25.187 °C
```

### Rules

```bash
make
make clean
make distclean
```

## References
[1] https://www.waveshare.com/wiki/Raspberry_Pi_Tutorial_Series:_1-Wire_DS18B20_Sensor
