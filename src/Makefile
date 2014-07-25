#
# OMNeT++/OMNEST Makefile for iec61850model
#
# This file was generated with the command:
#  opp_makemake -f --deep -I../../inetmanet-2.0-integration/src/transport/contract -I../../inetmanet-2.0-integration/src/wpan/networklayer/contract -I../../inetmanet-2.0-integration/src/networklayer/icmpv6 -I../../inetmanet-2.0-integration/src/transport/udp -I../../inetmanet-2.0-integration/src/linklayer/common -I../../inetmanet-2.0-integration/src/util -I../../inetmanet-2.0-integration/src/wpan/phyLayer/ieee802154 -I../../inetmanet-2.0-integration/src/util/headerserializers/udp -I../../inetmanet-2.0-integration/src/mobility/models -I../../inetmanet-2.0-integration/src/world/powercontrol -I../../inetmanet-2.0-integration/src/networklayer/contract -I../../inetmanet-2.0-integration/src/networklayer/xmipv6 -I../../inetmanet-2.0-integration/src/networklayer/common -I../../inetmanet-2.0-integration/src/linklayer/radio -I../../inetmanet-2.0-integration/src/networklayer/ipv6tunneling -I../../inetmanet-2.0-integration/src/networklayer/manetrouting/base -I../../inetmanet-2.0-integration/src/wpan/linklayer/ieee802154/mac -I../../inetmanet-2.0-integration/src/linklayer/contract -I../../inetmanet-2.0-integration/src/linklayer/ieee80211mesh/locator -I../../inetmanet-2.0-integration/src/networklayer/ipv6 -I../../inetmanet-2.0-integration/src/linklayer/ethernet -I../../inetmanet-2.0-integration/src/networklayer/arp -I../../inetmanet-2.0-integration/src/linklayer/radio/propagation -I../../inetmanet-2.0-integration/src/battery/models -I../../inetmanet-2.0-integration/src/util/headerserializers/sctp -I../../inetmanet-2.0-integration/src/world/obstacles -I../../inetmanet-2.0-integration/src/util/headerserializers/ipv4 -I../../inetmanet-2.0-integration/src/mobility -I../../inetmanet-2.0-integration/src -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/mac -I../../inetmanet-2.0-integration/src/networklayer/ipv4 -I../../inetmanet-2.0-integration/src/base -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/radio -I../../inetmanet-2.0-integration/src/applications/pingapp -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/mgmt -I../../inetmanet-2.0-integration/src/wpan/linklayer/ieee802154/contract -I../../inetmanet-2.0-integration/src/util/headerserializers/tcp -I../../inetmanet-2.0-integration/src/world/radio -I../../inetmanet-2.0-integration/src/transport/sctp -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/radio/errormodel -I../../inetmanet-2.0-integration/src/util/headerserializers -I../../inetmanet-2.0-integration/src/transport/tcp_common -I../../inetmanet-2.0-integration/src/applications/tcpapp -I../../inetmanet-2.0-integration/src/linklayer/ethernet/switch -I../../inetmanet-2.0-integration/src/linklayer/rstp -L../../inetmanet-2.0-integration/out/$(CONFIGNAME)/src -linet -DINET_IMPORT -KINETMANET_2_0_INTEGRATION_PROJ=../../inetmanet-2.0-integration
#

# Name of target to be created (-o option)
TARGET = iec61850model$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../inetmanet-2.0-integration/src/transport/contract \
    -I../../inetmanet-2.0-integration/src/wpan/networklayer/contract \
    -I../../inetmanet-2.0-integration/src/networklayer/icmpv6 \
    -I../../inetmanet-2.0-integration/src/transport/udp \
    -I../../inetmanet-2.0-integration/src/linklayer/common \
    -I../../inetmanet-2.0-integration/src/util \
    -I../../inetmanet-2.0-integration/src/wpan/phyLayer/ieee802154 \
    -I../../inetmanet-2.0-integration/src/util/headerserializers/udp \
    -I../../inetmanet-2.0-integration/src/mobility/models \
    -I../../inetmanet-2.0-integration/src/world/powercontrol \
    -I../../inetmanet-2.0-integration/src/networklayer/contract \
    -I../../inetmanet-2.0-integration/src/networklayer/xmipv6 \
    -I../../inetmanet-2.0-integration/src/networklayer/common \
    -I../../inetmanet-2.0-integration/src/linklayer/radio \
    -I../../inetmanet-2.0-integration/src/networklayer/ipv6tunneling \
    -I../../inetmanet-2.0-integration/src/networklayer/manetrouting/base \
    -I../../inetmanet-2.0-integration/src/wpan/linklayer/ieee802154/mac \
    -I../../inetmanet-2.0-integration/src/linklayer/contract \
    -I../../inetmanet-2.0-integration/src/linklayer/ieee80211mesh/locator \
    -I../../inetmanet-2.0-integration/src/networklayer/ipv6 \
    -I../../inetmanet-2.0-integration/src/linklayer/ethernet \
    -I../../inetmanet-2.0-integration/src/networklayer/arp \
    -I../../inetmanet-2.0-integration/src/linklayer/radio/propagation \
    -I../../inetmanet-2.0-integration/src/battery/models \
    -I../../inetmanet-2.0-integration/src/util/headerserializers/sctp \
    -I../../inetmanet-2.0-integration/src/world/obstacles \
    -I../../inetmanet-2.0-integration/src/util/headerserializers/ipv4 \
    -I../../inetmanet-2.0-integration/src/mobility \
    -I../../inetmanet-2.0-integration/src \
    -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/mac \
    -I../../inetmanet-2.0-integration/src/networklayer/ipv4 \
    -I../../inetmanet-2.0-integration/src/base \
    -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/radio \
    -I../../inetmanet-2.0-integration/src/applications/pingapp \
    -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/mgmt \
    -I../../inetmanet-2.0-integration/src/wpan/linklayer/ieee802154/contract \
    -I../../inetmanet-2.0-integration/src/util/headerserializers/tcp \
    -I../../inetmanet-2.0-integration/src/world/radio \
    -I../../inetmanet-2.0-integration/src/transport/sctp \
    -I../../inetmanet-2.0-integration/src/linklayer/ieee80211/radio/errormodel \
    -I../../inetmanet-2.0-integration/src/util/headerserializers \
    -I../../inetmanet-2.0-integration/src/transport/tcp_common \
    -I../../inetmanet-2.0-integration/src/applications/tcpapp \
    -I../../inetmanet-2.0-integration/src/linklayer/ethernet/switch \
    -I../../inetmanet-2.0-integration/src/linklayer/rstp \
    -I. \
    -Iapplications \
    -Ibasic \
    -Idevices \
    -IelectricSubstation \
    -Ilinklayer \
    -Ilinklayer/ethernet \
    -Ilinklayer/ethernet/classOfService \
    -Ilinklayer/ethernet/relayUnit \
    -Ilinklayer/ethernet/switch1Qsublayer \
    -Ilinklayer/ieee8021QConfigurator \
    -Inodes \
    -Inodes/ethernet \
    -Inodes/iec61850 \
    -Inodes/iec61850/ied \
    -Inodes/iec61850/ied/applicationProfile \
    -Inodes/iec61850/ied/applicationProfile/goose \
    -Inodes/iec61850/ied/applicationProfile/mms \
    -Inodes/iec61850/ied/applicationProfile/sampledValues \
    -Iprp \
    -Isas \
    -Itests \
    -Itests/SubstationNetworkTopologies \
    -Itests/SubstationNetworkTopologies/results \
    -Itests/enhancedSwitchTest \
    -Itests/enhancedSwitchTest/results \
    -Itests/genericIedTest \
    -Itests/genericIedTest/results \
    -Itests/iedSwitchTest \
    -Itests/iedSwitchTest/results \
    -Itests/prp \
    -Itests/results \
    -Itests/sasTest \
    -Itests/sasTest/results \
    -Itests/substationSidhu2007 \
    -Itests/substationSidhu2007/results \
    -Itests/substationSidhu2007/results/pcap \
    -Itests/substationTest \
    -Itests/substationTest/results \
    -Itests/switch1Q \
    -Itests/switch1Q/results \
    -Iutil

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inetmanet-2.0-integration/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath ../../inetmanet-2.0-integration/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/applications/iec61850trafgen.o \
    $O/basic/switchLayer.o \
    $O/basic/table8021Q.o \
    $O/basic/dispatcher.o \
    $O/basic/MACRelayUnitModified.o \
    $O/basic/MACRelay1Q.o \
    $O/linklayer/Layer8021Q.o \
    $O/linklayer/ethernet/classOfService/EthFrameClassifier.o \
    $O/linklayer/ethernet/relayUnit/MACRelayUnitHost.o \
    $O/linklayer/ethernet/relayUnit/MACRelayUnit1Q.o \
    $O/linklayer/ethernet/switch1Qsublayer/ieee1QLayer.o \
    $O/linklayer/ieee8021QConfigurator/ieee8021QConfigurator.o \
    $O/nodes/iec61850/ied/applicationProfile/scsm.o \
    $O/nodes/iec61850/ied/applicationProfile/goose/GOOSEApp.o \
    $O/nodes/iec61850/ied/applicationProfile/mms/MMSAppClient.o \
    $O/nodes/iec61850/ied/applicationProfile/mms/MMSAppServer.o \
    $O/nodes/iec61850/ied/applicationProfile/sampledValues/SVApp.o \
    $O/prp/EtherMACDANP.o \
    $O/prp/LinkRedundancyEntity.o \
    $O/util/pcapper.o \
    $O/applications/iec61850message_m.o \
    $O/linklayer/Ieee8021QFrame_m.o \
    $O/nodes/iec61850/ied/applicationProfile/goose/goose_m.o \
    $O/nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue_m.o

# Message files
MSGFILES = \
    applications/iec61850message.msg \
    linklayer/Ieee8021QFrame.msg \
    nodes/iec61850/ied/applicationProfile/goose/goose.msg \
    nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue.msg

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
	$(Q)-rm -f applications/*_m.cc applications/*_m.h
	$(Q)-rm -f basic/*_m.cc basic/*_m.h
	$(Q)-rm -f devices/*_m.cc devices/*_m.h
	$(Q)-rm -f electricSubstation/*_m.cc electricSubstation/*_m.h
	$(Q)-rm -f linklayer/*_m.cc linklayer/*_m.h
	$(Q)-rm -f linklayer/ethernet/*_m.cc linklayer/ethernet/*_m.h
	$(Q)-rm -f linklayer/ethernet/classOfService/*_m.cc linklayer/ethernet/classOfService/*_m.h
	$(Q)-rm -f linklayer/ethernet/relayUnit/*_m.cc linklayer/ethernet/relayUnit/*_m.h
	$(Q)-rm -f linklayer/ethernet/switch1Qsublayer/*_m.cc linklayer/ethernet/switch1Qsublayer/*_m.h
	$(Q)-rm -f linklayer/ieee8021QConfigurator/*_m.cc linklayer/ieee8021QConfigurator/*_m.h
	$(Q)-rm -f nodes/*_m.cc nodes/*_m.h
	$(Q)-rm -f nodes/ethernet/*_m.cc nodes/ethernet/*_m.h
	$(Q)-rm -f nodes/iec61850/*_m.cc nodes/iec61850/*_m.h
	$(Q)-rm -f nodes/iec61850/ied/*_m.cc nodes/iec61850/ied/*_m.h
	$(Q)-rm -f nodes/iec61850/ied/applicationProfile/*_m.cc nodes/iec61850/ied/applicationProfile/*_m.h
	$(Q)-rm -f nodes/iec61850/ied/applicationProfile/goose/*_m.cc nodes/iec61850/ied/applicationProfile/goose/*_m.h
	$(Q)-rm -f nodes/iec61850/ied/applicationProfile/mms/*_m.cc nodes/iec61850/ied/applicationProfile/mms/*_m.h
	$(Q)-rm -f nodes/iec61850/ied/applicationProfile/sampledValues/*_m.cc nodes/iec61850/ied/applicationProfile/sampledValues/*_m.h
	$(Q)-rm -f prp/*_m.cc prp/*_m.h
	$(Q)-rm -f sas/*_m.cc sas/*_m.h
	$(Q)-rm -f tests/*_m.cc tests/*_m.h
	$(Q)-rm -f tests/SubstationNetworkTopologies/*_m.cc tests/SubstationNetworkTopologies/*_m.h
	$(Q)-rm -f tests/SubstationNetworkTopologies/results/*_m.cc tests/SubstationNetworkTopologies/results/*_m.h
	$(Q)-rm -f tests/enhancedSwitchTest/*_m.cc tests/enhancedSwitchTest/*_m.h
	$(Q)-rm -f tests/enhancedSwitchTest/results/*_m.cc tests/enhancedSwitchTest/results/*_m.h
	$(Q)-rm -f tests/genericIedTest/*_m.cc tests/genericIedTest/*_m.h
	$(Q)-rm -f tests/genericIedTest/results/*_m.cc tests/genericIedTest/results/*_m.h
	$(Q)-rm -f tests/iedSwitchTest/*_m.cc tests/iedSwitchTest/*_m.h
	$(Q)-rm -f tests/iedSwitchTest/results/*_m.cc tests/iedSwitchTest/results/*_m.h
	$(Q)-rm -f tests/prp/*_m.cc tests/prp/*_m.h
	$(Q)-rm -f tests/results/*_m.cc tests/results/*_m.h
	$(Q)-rm -f tests/sasTest/*_m.cc tests/sasTest/*_m.h
	$(Q)-rm -f tests/sasTest/results/*_m.cc tests/sasTest/results/*_m.h
	$(Q)-rm -f tests/substationSidhu2007/*_m.cc tests/substationSidhu2007/*_m.h
	$(Q)-rm -f tests/substationSidhu2007/results/*_m.cc tests/substationSidhu2007/results/*_m.h
	$(Q)-rm -f tests/substationSidhu2007/results/pcap/*_m.cc tests/substationSidhu2007/results/pcap/*_m.h
	$(Q)-rm -f tests/substationTest/*_m.cc tests/substationTest/*_m.h
	$(Q)-rm -f tests/substationTest/results/*_m.cc tests/substationTest/results/*_m.h
	$(Q)-rm -f tests/switch1Q/*_m.cc tests/switch1Q/*_m.h
	$(Q)-rm -f tests/switch1Q/results/*_m.cc tests/switch1Q/results/*_m.h
	$(Q)-rm -f util/*_m.cc util/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc applications/*.cc basic/*.cc devices/*.cc electricSubstation/*.cc linklayer/*.cc linklayer/ethernet/*.cc linklayer/ethernet/classOfService/*.cc linklayer/ethernet/relayUnit/*.cc linklayer/ethernet/switch1Qsublayer/*.cc linklayer/ieee8021QConfigurator/*.cc nodes/*.cc nodes/ethernet/*.cc nodes/iec61850/*.cc nodes/iec61850/ied/*.cc nodes/iec61850/ied/applicationProfile/*.cc nodes/iec61850/ied/applicationProfile/goose/*.cc nodes/iec61850/ied/applicationProfile/mms/*.cc nodes/iec61850/ied/applicationProfile/sampledValues/*.cc prp/*.cc sas/*.cc tests/*.cc tests/SubstationNetworkTopologies/*.cc tests/SubstationNetworkTopologies/results/*.cc tests/enhancedSwitchTest/*.cc tests/enhancedSwitchTest/results/*.cc tests/genericIedTest/*.cc tests/genericIedTest/results/*.cc tests/iedSwitchTest/*.cc tests/iedSwitchTest/results/*.cc tests/prp/*.cc tests/results/*.cc tests/sasTest/*.cc tests/sasTest/results/*.cc tests/substationSidhu2007/*.cc tests/substationSidhu2007/results/*.cc tests/substationSidhu2007/results/pcap/*.cc tests/substationTest/*.cc tests/substationTest/results/*.cc tests/switch1Q/*.cc tests/switch1Q/results/*.cc util/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/applications/iec61850message_m.o: applications/iec61850message_m.cc \
	applications/iec61850message_m.h
$O/applications/iec61850trafgen.o: applications/iec61850trafgen.cc \
	applications/iec61850message_m.h \
	applications/iec61850trafgen.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h
$O/basic/MACRelay1Q.o: basic/MACRelay1Q.cc \
	basic/MACRelay1Q.h \
	linklayer/Ieee8021QFrame_m.h \
	linklayer/ieee8021QConfigurator/ieee8021QConfigurator.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/MACRelayUnitSTPNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/STPDefinitions.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/bpdu_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/stpTimers_m.h
$O/basic/MACRelayUnitModified.o: basic/MACRelayUnitModified.cc \
	basic/MACRelayUnitModified.h \
	basic/table8021Q.h \
	linklayer/Ieee8021QFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/MACRelayUnitSTPNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/STPDefinitions.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/bpdu_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/stpTimers_m.h
$O/basic/dispatcher.o: basic/dispatcher.cc \
	applications/iec61850message_m.h \
	basic/dispatcher.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/arp/ARPPacket_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/ipv4/IGMPMessage_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h
$O/basic/switchLayer.o: basic/switchLayer.cc \
	basic/switchLayer.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h
$O/basic/table8021Q.o: basic/table8021Q.cc \
	basic/table8021Q.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h
$O/linklayer/Ieee8021QFrame_m.o: linklayer/Ieee8021QFrame_m.cc \
	linklayer/Ieee8021QFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h
$O/linklayer/Layer8021Q.o: linklayer/Layer8021Q.cc \
	applications/iec61850message_m.h \
	linklayer/Ieee8021QFrame_m.h \
	linklayer/Layer8021Q.h \
	linklayer/ieee8021QConfigurator/ieee8021QConfigurator.h \
	nodes/iec61850/ied/applicationProfile/goose/goose_m.h \
	nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/IPassiveQueue.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherMAC.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherMACBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/arp/ARPPacket_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/ipv4/IGMPMessage_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h
$O/linklayer/ethernet/classOfService/EthFrameClassifier.o: linklayer/ethernet/classOfService/EthFrameClassifier.cc \
	linklayer/Ieee8021QFrame_m.h \
	linklayer/ethernet/classOfService/EthFrameClassifier.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h
$O/linklayer/ethernet/relayUnit/MACRelayUnit1Q.o: linklayer/ethernet/relayUnit/MACRelayUnit1Q.cc \
	linklayer/Ieee8021QFrame_m.h \
	linklayer/ethernet/relayUnit/MACRelayUnit1Q.h \
	linklayer/ieee8021QConfigurator/ieee8021QConfigurator.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/IPassiveQueue.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherMACBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/MACRelayUnitSTPNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/STPDefinitions.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/bpdu_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/stpTimers_m.h
$O/linklayer/ethernet/relayUnit/MACRelayUnitHost.o: linklayer/ethernet/relayUnit/MACRelayUnitHost.cc \
	linklayer/Ieee8021QFrame_m.h \
	linklayer/ethernet/relayUnit/MACRelayUnit1Q.h \
	linklayer/ethernet/relayUnit/MACRelayUnitHost.h \
	linklayer/ieee8021QConfigurator/ieee8021QConfigurator.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/IPassiveQueue.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherMACBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/switch/MACRelayUnitNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/MACRelayUnitSTPNP.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/STPDefinitions.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/bpdu_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/rstp/stpTimers_m.h
$O/linklayer/ethernet/switch1Qsublayer/ieee1QLayer.o: linklayer/ethernet/switch1Qsublayer/ieee1QLayer.cc \
	linklayer/ethernet/switch1Qsublayer/ieee1QLayer.h
$O/linklayer/ieee8021QConfigurator/ieee8021QConfigurator.o: linklayer/ieee8021QConfigurator/ieee8021QConfigurator.cc \
	linklayer/ieee8021QConfigurator/ieee8021QConfigurator.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h
$O/nodes/iec61850/ied/applicationProfile/scsm.o: nodes/iec61850/ied/applicationProfile/scsm.cc \
	nodes/iec61850/ied/applicationProfile/scsm.h
$O/nodes/iec61850/ied/applicationProfile/goose/GOOSEApp.o: nodes/iec61850/ied/applicationProfile/goose/GOOSEApp.cc \
	nodes/iec61850/ied/applicationProfile/goose/GOOSEApp.h \
	nodes/iec61850/ied/applicationProfile/goose/goose_m.h \
	nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h
$O/nodes/iec61850/ied/applicationProfile/goose/goose_m.o: nodes/iec61850/ied/applicationProfile/goose/goose_m.cc \
	nodes/iec61850/ied/applicationProfile/goose/goose_m.h
$O/nodes/iec61850/ied/applicationProfile/mms/MMSAppClient.o: nodes/iec61850/ied/applicationProfile/mms/MMSAppClient.cc \
	nodes/iec61850/ied/applicationProfile/mms/MMSAppClient.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/applications/tcpapp/TCPGenericCliAppBase.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPvXAddressResolver.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/transport/contract/TCPCommand_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/transport/contract/TCPSocket.h
$O/nodes/iec61850/ied/applicationProfile/mms/MMSAppServer.o: nodes/iec61850/ied/applicationProfile/mms/MMSAppServer.cc \
	nodes/iec61850/ied/applicationProfile/mms/MMSAppServer.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/applications/tcpapp/GenericAppMsg_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/transport/contract/TCPCommand_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/transport/contract/TCPSocket.h
$O/nodes/iec61850/ied/applicationProfile/sampledValues/SVApp.o: nodes/iec61850/ied/applicationProfile/sampledValues/SVApp.cc \
	nodes/iec61850/ied/applicationProfile/sampledValues/SVApp.h \
	nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h
$O/nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue_m.o: nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue_m.cc \
	nodes/iec61850/ied/applicationProfile/sampledValues/sampledValue_m.h
$O/prp/EtherMACDANP.o: prp/EtherMACDANP.cc \
	prp/EtherMACDANP.h
$O/prp/LinkRedundancyEntity.o: prp/LinkRedundancyEntity.cc \
	prp/LinkRedundancyEntity.h
$O/util/pcapper.o: util/pcapper.cc \
	applications/iec61850message_m.h \
	linklayer/Ieee8021QFrame_m.h \
	util/pcapper.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/base/INETDefs.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_2_0_INTEGRATION_PROJ)/src/linklayer/ethernet/Ethernet.h

