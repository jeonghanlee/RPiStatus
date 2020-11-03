#!../../bin/linux-arm/rpiStats

#- You may have to change rpiStats to something else
#- everywhere it appears in this file

#< envPaths

## Register all support components
dbLoadDatabase("../../dbd/rpiStats.dbd",0,0)
rpiStats_registerRecordDeviceDriver(pdbbase) 

## Load record instances
dbLoadRecords("../../db/rpiStats.db","user=pi")

iocInit()

## Start any sequence programs
#seq sncrpiStats,"user=pi"
