#
# OMNeT++/OMNEST Makefile for iec61850model
#
# This file was generated with the command:
#  opp_makemake -f --deep --nolink -O out -d src -d simulations -X. -L../inetmanet-2.0-integration/out/$(CONFIGNAME)/src -linet -DINET_IMPORT -KINETMANET_2_0_INTEGRATION_PROJ=../inetmanet-2.0-integration
#

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Other makefile variables (-K)
INETMANET_2_0_INTEGRATION_PROJ=../inetmanet-2.0-integration

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

all:  submakedirs Makefile
	@# Do nothing

submakedirs:  src_dir simulations_dir

.PHONY: all clean cleanall depend msgheaders  src simulations
src: src_dir
simulations: simulations_dir

src_dir:
	cd src && $(MAKE) all

simulations_dir:
	cd simulations && $(MAKE) all

msgheaders:
	$(Q)cd src && $(MAKE) msgheaders
	$(Q)cd simulations && $(MAKE) msgheaders

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f iec61850model iec61850model.exe libiec61850model.so libiec61850model.a libiec61850model.dll libiec61850model.dylib

	-$(Q)cd src && $(MAKE) clean
	-$(Q)cd simulations && $(MAKE) clean

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)-cd src && if [ -f Makefile ]; then $(MAKE) depend; fi
	$(Q)-cd simulations && if [ -f Makefile ]; then $(MAKE) depend; fi

