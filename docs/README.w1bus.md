# w1 sysfs

w1_therm provides basic temperature conversion for ds18*20 devices, and the ds28ea00 device [1].

Supported family codes:

```
W1_THERM_DS18S20 	0x10
W1_THERM_DS1822 	0x22
W1_THERM_DS18B20 	0x28
W1_THERM_DS1825 	0x3B
W1_THERM_DS28EA00 	0x42
```

## w1_master

```
$ cat /sys/bus/w1/devices/w1_bus_master1/w1_master_slave_count 
5

$ cat -n /sys/bus/w1/devices/w1_bus_master1/w1_master_slaves
     1	28-0301a2791321
     2	28-0301a279e7d9
     3	28-0301a279b4f9
     4	28-3c01d6079a0d
     5	28-0301a279d4ef
```


## w1 slave


```bash
/sys/bus/w1/devices/28-0301a2791321# tree
.
├── alarms
├── driver -> ../../../bus/w1/drivers/w1_slave_driver
├── eeprom
├── ext_power
├── hwmon
│   └── hwmon1
│       ├── device -> ../../../28-0301a2791321
│       ├── name
│       ├── power
│       │   ├── autosuspend_delay_ms
│       │   ├── control
│       │   ├── runtime_active_time
│       │   ├── runtime_status
│       │   └── runtime_suspended_time
│       ├── subsystem -> ../../../../../class/hwmon
│       ├── temp1_input
│       └── uevent
├── id
├── name
├── power
│   ├── autosuspend_delay_ms
│   ├── control
│   ├── runtime_active_time
│   ├── runtime_status
│   └── runtime_suspended_time
├── resolution
├── subsystem -> ../../../bus/w1
├── temperature
├── uevent
└── w1_slave
```

```
ls -ltar
total 0
drwxr-xr-x 8 root root    0 Nov  7 15:43 ..
-rw-r--r-- 1 root root 4096 Nov  7 15:43 uevent
lrwxrwxrwx 1 root root    0 Nov  7 15:43 subsystem -> ../../../bus/w1
drwxr-xr-x 3 root root    0 Nov  7 15:43 hwmon
lrwxrwxrwx 1 root root    0 Nov  7 15:43 driver -> ../../../bus/w1/drivers/w1_slave_driver
drwxr-xr-x 4 root root    0 Nov  7 15:43 .
-r--r--r-- 1 root root 4096 Nov  7 16:55 temperature
-rw-r--r-- 1 root root 4096 Nov  7 17:04 w1_slave
-rw-r--r-- 1 root root 4096 Nov  7 17:04 resolution
drwxr-xr-x 2 root root    0 Nov  7 17:04 power
-r--r--r-- 1 root root 4096 Nov  7 17:04 name
-r--r--r-- 1 root root 4096 Nov  7 17:04 id
-r--r--r-- 1 root root 4096 Nov  7 17:04 ext_power
--w------- 1 root root 4096 Nov  7 17:04 eeprom
-rw-r--r-- 1 root root 4096 Nov  7 17:04 alarms
```

## `temperature` millidegrees Celsius (R) 

```bash
$ cat temperature 
23437
```

## `w1_slave` (RW)

```bash
# cat w1_slave 
77 01 55 05 7f a5 a5 66 17 : crc=17 YES
77 01 55 05 7f a5 a5 66 17 t=23437
```

## `resolution` (RW)

```bash
# cat resolution 
12
```

This change is tempoary. We can save them into EEPROM. But the EEPROM has a limited amount of writes (>50k).


     3	28-0301a279b4f9

```
# more temperature 
23375
# echo 9 > resolution 
# more resolution 
9
# more temperature (x2) 
23000

# echo "10" > resolution 
#  more resolution 
10
# more temperature 
23000
# more temperature 
23250
# echo "11" > resolution 
# more resolution 
11
# more temperature 
23250
# more temperature 
23375
```





## `name` (R)

```bash
cat name 
28-0301a2791321
```

## 'id` (R)

```bash
 more id 
(!y�	
```

## `ext_power` (R)

```
more ext_power 
1
```
0: device parasite powered
1: device externally powered


## `alarms` (RW)

```
$ more alarms 
5 85
```

This allow read or write TH and TL (Temperature High an Low) alarms.Values shall be space separated and in the device range (typical -55 degC to 125degC) [1]. 



# References

[1] https://www.kernel.org/doc/html/latest/w1/slaves/w1_therm.html