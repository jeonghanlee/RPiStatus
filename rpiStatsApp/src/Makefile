TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = rpiStats
# rpiStats.dbd will be created and installed
DBD += rpiStats.dbd

# rpiStats.dbd will be made up from these files:
rpiStats_DBD += base.dbd

# Include dbd files from all support applications:
#rpiStats_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#rpiStats_LIBS += xxx

# rpiStats_registerRecordDeviceDriver.cpp derives from rpiStats.dbd
rpiStats_SRCS += rpiStats_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
rpiStats_SRCS_DEFAULT += rpiStatsMain.cpp
rpiStats_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#rpiStats_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
rpiStats_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

