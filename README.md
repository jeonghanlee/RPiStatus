# rpiStats

Raspberry PI [1] is the great system. Thanks to the mordern Linux Kernel sysfs [2], the CPU thermal zone temerature and 1-Wire sensors can be accessiable through sysfs. Thus, this repository is the EPICS IOC of them (CPU thermal zone, and 1-Wire sensor) for Raspberry PI without any dependent libraries.

It uses the similar approach which the exist EPICS module such as iocStats [3].

## EPICS IOC

**Not relaesed**

## Simple C Progrmas

See [c/README.md](c/README.md)


## Setup

|![OWS](docs/FiveW_with_rpi.png)|
| :---: |
|**Figure 1** Raspberry Pi 2 with five 1-Wire sensors.|



# References

[1] https://www.raspberrypi.org/

[2] https://www.kernel.org/doc/html/latest/admin-guide/sysfs-rules.html

[3] https://github.com/epics-modules/iocStats


