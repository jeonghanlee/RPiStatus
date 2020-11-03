TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = RPiStatus
# RPiStatus.dbd will be created and installed
DBD += RPiStatus.dbd

# RPiStatus.dbd will be made up from these files:
RPiStatus_DBD += base.dbd

# Include dbd files from all support applications:
#RPiStatus_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#RPiStatus_LIBS += xxx

# RPiStatus_registerRecordDeviceDriver.cpp derives from RPiStatus.dbd
RPiStatus_SRCS += RPiStatus_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
RPiStatus_SRCS_DEFAULT += RPiStatusMain.cpp
RPiStatus_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#RPiStatus_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
RPiStatus_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

