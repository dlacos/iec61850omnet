#
# OMNeT++/OMNEST Makefile for iec61850model
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -XTopologies -L../../inetmanet-2.0-integration/out/$(CONFIGNAME)/src -linet -DINET_IMPORT -KINETMANET_2_0_INTEGRATION_PROJ=../../inetmanet-2.0-integration
#

# Name of target to be created (-o option)
TARGET = iec61850model$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -IKanabar2009 \
    -IKanabar2009/results \
    -ISAS \
    -ISAS/old \
    -ISAS/results \
    -ISAS/results/HybridStar \
    -ISAS/results/HybridStar/VLANs \
    -ISAS/results/RingStar \
    -ISAS/results/RingStar/VLANs \
    -ISAS/results/RingStar/VLANs/link100 \
    -Isubstations \
    -Isubstations/results \
    -Ivalidation \
    -I"validation/Figuras doc dissertacao" \
    -Ivalidation/results \
    -Ivalidation/results/Sidhu2007 \
    -Ivalidation/results/Sidhu2007/link10 \
    -Ivalidation/results/Sidhu2007/link100

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inetmanet-2.0-integration/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath ../../inetmanet-2.0-integration/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = simulations
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS =

# Message files
MSGFILES =

# Other makefile variables (-K)
INETMANET_2_0_INTEGRATION_PROJ=../../inetmanet-2.0-integration

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f iec61850model iec61850model.exe libiec61850model.so libiec61850model.a libiec61850model.dll libiec61850model.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f Kanabar2009/*_m.cc Kanabar2009/*_m.h
	$(Q)-rm -f Kanabar2009/results/*_m.cc Kanabar2009/results/*_m.h
	$(Q)-rm -f SAS/*_m.cc SAS/*_m.h
	$(Q)-rm -f SAS/old/*_m.cc SAS/old/*_m.h
	$(Q)-rm -f SAS/results/*_m.cc SAS/results/*_m.h
	$(Q)-rm -f SAS/results/HybridStar/*_m.cc SAS/results/HybridStar/*_m.h
	$(Q)-rm -f SAS/results/HybridStar/VLANs/*_m.cc SAS/results/HybridStar/VLANs/*_m.h
	$(Q)-rm -f SAS/results/RingStar/*_m.cc SAS/results/RingStar/*_m.h
	$(Q)-rm -f SAS/results/RingStar/VLANs/*_m.cc SAS/results/RingStar/VLANs/*_m.h
	$(Q)-rm -f SAS/results/RingStar/VLANs/link100/*_m.cc SAS/results/RingStar/VLANs/link100/*_m.h
	$(Q)-rm -f substations/*_m.cc substations/*_m.h
	$(Q)-rm -f substations/results/*_m.cc substations/results/*_m.h
	$(Q)-rm -f validation/*_m.cc validation/*_m.h
	$(Q)-rm -f validation/Figuras doc dissertacao/*_m.cc validation/Figuras doc dissertacao/*_m.h
	$(Q)-rm -f validation/results/*_m.cc validation/results/*_m.h
	$(Q)-rm -f validation/results/Sidhu2007/*_m.cc validation/results/Sidhu2007/*_m.h
	$(Q)-rm -f validation/results/Sidhu2007/link10/*_m.cc validation/results/Sidhu2007/link10/*_m.h
	$(Q)-rm -f validation/results/Sidhu2007/link100/*_m.cc validation/results/Sidhu2007/link100/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc Kanabar2009/*.cc Kanabar2009/results/*.cc SAS/*.cc SAS/old/*.cc SAS/results/*.cc SAS/results/HybridStar/*.cc SAS/results/HybridStar/VLANs/*.cc SAS/results/RingStar/*.cc SAS/results/RingStar/VLANs/*.cc SAS/results/RingStar/VLANs/link100/*.cc substations/*.cc substations/results/*.cc validation/*.cc validation/Figuras doc dissertacao/*.cc validation/results/*.cc validation/results/Sidhu2007/*.cc validation/results/Sidhu2007/link10/*.cc validation/results/Sidhu2007/link100/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.

