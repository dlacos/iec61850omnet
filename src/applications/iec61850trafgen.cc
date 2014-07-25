//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "iec61850trafgen.h"
#include "Ieee802Ctrl_m.h"
#include "iec61850message_m.h"

Define_Module(Iec61850trafgen);

simsignal_t Iec61850trafgen::sentPkSignal = SIMSIGNAL_NULL;
simsignal_t Iec61850trafgen::rcvdPkSignal = SIMSIGNAL_NULL;
simsignal_t Iec61850trafgen::rcvdTrip1ASignal = SIMSIGNAL_NULL;

Iec61850trafgen::Iec61850trafgen()
{
    timerMsg = NULL;
}

Iec61850trafgen::~Iec61850trafgen()
{
    cancelAndDelete(timerMsg);
}

void Iec61850trafgen::initialize(int stage)
{
    // TODO - Generated method body
    // we can only initialize in the 2nd stage (stage==1), because
    // assignment of "auto" MAC addresses takes place in stage 0
    if (stage == 1)
    {
        sendInterval = &par("sendInterval");
        numPacketsPerBurst = &par("numPacketsPerBurst");
        packetLength = &par("packetLength");
        etherType = par("etherType");
        vid = par("vid");

        seqNum = 0;
        WATCH(seqNum);

        // statistics
        packetsSent = packetsReceived = 0;
        sentPkSignal = registerSignal("sentPk");
        rcvdPkSignal = registerSignal("rcvdPk");
        rcvdTrip1ASignal = registerSignal("rcvdTrip1A");
        WATCH(packetsSent);
        WATCH(packetsReceived);

        destMACAddress = resolveDestMACAddress();
        //cModule *srcStation = getParentModule();// simulation.getModuleByPath());
        //cModule *srcMAC = srcStation->getSubmodule("mac");
        //srcMACAddress.setAddress(srcMAC->par("address"));


        // if no dest address given, nothing to do
        if (destMACAddress.isUnspecified())
            return;

        simtime_t startTime = par("startTime");
        stopTime = par("stopTime");
        if (stopTime != 0 && stopTime <= startTime)
            error("Invalid startTime/stopTime parameters");

        timerMsg = new cMessage("generateNextPacket");
        scheduleAt(startTime, timerMsg);
    }
}

void Iec61850trafgen::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (msg->isSelfMessage())
    {
        sendBurstPackets();
        simtime_t d = simTime() + sendInterval->doubleValue();
        if (stopTime == 0 || d < stopTime)
            scheduleAt(d, msg);
    }
    else
    {
        receivePacket(check_and_cast<cPacket*>(msg));
    }
}

MACAddress Iec61850trafgen::resolveDestMACAddress()
{
    MACAddress destMACAddress;
    const char *destAddress = par("destAddress");
    if (destAddress[0])
    {
        // try as mac address first, then as a module
        if (!destMACAddress.tryParse(destAddress))
        {
            cModule *destStation = simulation.getModuleByPath(destAddress);
            if (!destStation)
                error("cannot resolve MAC address '%s': not a 12-hex-digit MAC address or a valid module path name", destAddress);

            cModule *destMAC = destStation->getSubmodule("mac");
            if (!destMAC)
                error("module '%s' has no 'mac' submodule", destAddress);

            destMACAddress.setAddress(destMAC->par("address"));
        }
    }
    return destMACAddress;
}

void Iec61850trafgen::sendBurstPackets()
{
    int n = numPacketsPerBurst->longValue();
    for (int i = 0; i < n; i++)
    {
        seqNum++;

        char msgname[40];
        sprintf(msgname, "pk-%d-%ld", getId(), seqNum);
        EV << "Generating packet `" << msgname << "'\n";

        //cPacket *datapacket = new cPacket(msgname, IEEE802CTRL_DATA);
        Iec61850message *datapacket = new Iec61850message(msgname, IEEE802CTRL_DATA);

        long len = packetLength->longValue();
        int eType = par("eType");
        int tci = par("tci");
        int vid = par("vid");
        datapacket->setByteLength(len);
        datapacket->setEType(eType);
        datapacket->setTci(tci);
        datapacket->setVid(vid);

        Ieee802Ctrl *etherctrl = new Ieee802Ctrl();
        etherctrl->setEtherType(etherType);
        etherctrl->setDest(destMACAddress);
        etherctrl->setSrc(srcMACAddress);
        datapacket->setControlInfo(etherctrl);

        emit(sentPkSignal, datapacket);
        send(datapacket, "out");
        packetsSent++;
    }
}

void Iec61850trafgen::receivePacket(cPacket *msg)
{
    EV << "Received packet `" << msg->getName() << "'\n";

    packetsReceived++;
    emit(rcvdPkSignal, msg);
    if(dynamic_cast<Iec61850message *> (msg->getEncapsulatedPacket()) != NULL)
    {
        //EV << "IEC61850 message received" << endl;
        emit(rcvdTrip1ASignal,msg);
    }

    delete msg;
}

void Iec61850trafgen::finish()
{
    cancelAndDelete(timerMsg);
    timerMsg = NULL;
}
