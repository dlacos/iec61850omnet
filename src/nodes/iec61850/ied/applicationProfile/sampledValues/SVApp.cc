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

#include "SVApp.h"

Define_Module(SVApp);

simsignal_t SVApp::sentPkSignal = SIMSIGNAL_NULL;
simsignal_t SVApp::rcvdPkSignal = SIMSIGNAL_NULL;
simsignal_t SVApp::rcvdSampledValueSignal = SIMSIGNAL_NULL;

SVApp::SVApp()
{
    timerMsg = NULL;
}

SVApp::~SVApp()
{
    cancelAndDelete(timerMsg);
}

void SVApp::initialize(int stage)
{
    // TODO - Generated method body
    if (stage == 1)
    {
        sendInterval = &par("sendInterval");
        numPacketsPerBurst = &par("numPacketsPerBurst");
        packetLength = &par("packetLength");
        etherType = par("etherType");

        vid = par("vid");
        tpid = par("tpid");
        appid = par("appid");
        priority = par("priority");

        seqNum = 0;
        WATCH(seqNum);

        // statistics
        packetsSent = packetsReceived = 0;
        sentPkSignal = registerSignal("sentPk");
        rcvdPkSignal = registerSignal("rcvdPk");
        rcvdSampledValueSignal = registerSignal("rcvdSV");
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

void SVApp::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (msg->isSelfMessage())
    {
        if (ev.isGUI()) getParentModule()->bubble("Sending a Sampled Value message");
        sendBurstPackets(destMACAddress);
        simtime_t d = simTime() + sendInterval->doubleValue();
        if (stopTime == 0 || d < stopTime)
            scheduleAt(d, msg);
    }
    else
    {
/*        if(reply)
        {
            sendReply();
            if (ev.isGUI()) getParentModule()->bubble("GOOSE Reply");
        }*/
        receivePacket(check_and_cast<cPacket*>(msg));

    }
}
MACAddress SVApp::resolveDestMACAddress()
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

void SVApp::sendBurstPackets(MACAddress destMAC)
{
    int n = numPacketsPerBurst->longValue();
    for (int i = 0; i < n; i++)
    {
        seqNum++;

        char msgname[40];
        sprintf(msgname, "sampledValue-%d-%ld", getId(), seqNum);
        EV << "Generating Sampled Value message `" << msgname << "'\n";

        //cPacket *datapacket = new cPacket(msgname, IEEE802CTRL_DATA);
        SampledValue *datapacket = new SampledValue(msgname, IEEE802CTRL_DATA);

        long len = packetLength->longValue();


        datapacket->setAppid(appid);
        datapacket->setLength(158);
        datapacket->setByteLength(len);
        datapacket->setReserved1(0);
        datapacket->setReserved2(0);
        datapacket->setEtherType(etherType);
        datapacket->setTpid(tpid);
        datapacket->setVid(vid);
        datapacket->setPriority(priority);
        datapacket->setCfi(cfi);

        Ieee802Ctrl *etherctrl = new Ieee802Ctrl();
        etherctrl->setEtherType(etherType);
        etherctrl->setDest(destMAC);
        etherctrl->setSrc(srcMACAddress);
        datapacket->setControlInfo(etherctrl);

        emit(sentPkSignal, datapacket);
        send(datapacket, "out");
        packetsSent++;
    }
}

void SVApp::receivePacket(cPacket *msg)
{
    EV << "Received packet `" << msg->getName() << "'\n";

    packetsReceived++;
    emit(rcvdPkSignal, msg);
    if(dynamic_cast<SampledValue *> (msg->getEncapsulatedPacket()) != NULL)
    {
        //EV << "IEC61850 message received" << endl;
        emit(rcvdSampledValueSignal,msg);
    }

    delete msg;
}
/*void GOOSEApp::sendReply()
{
    MACAddress tmpMac;
    tmpMac.setAddress("FFFFFFFFFFFF");
    sendBurstPackets(tmpMac);
}*/

void SVApp::finish()
{
    cancelAndDelete(timerMsg);
    timerMsg = NULL;
}
