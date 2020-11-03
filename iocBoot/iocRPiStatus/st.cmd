#!../../bin/linux-arm/RPiStatus

#- You may have to change RPiStatus to something else
#- everywhere it appears in this file

#< envPaths

## Register all support components
dbLoadDatabase("../../dbd/RPiStatus.dbd",0,0)
RPiStatus_registerRecordDeviceDriver(pdbbase) 

## Load record instances
dbLoadRecords("../../db/RPiStatus.db","user=pi")

iocInit()

## Start any sequence programs
#seq sncRPiStatus,"user=pi"
