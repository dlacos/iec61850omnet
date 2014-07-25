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

package iec61850model.applications;

//
// TODO auto-generated module
//
simple Iec61850trafgen
{
    parameters:
        string destAddress = default("");  // destination MAC address, or module path name of destination station; empty means off       
        int etherType = default(0x8100);  // etherType to set on outgoing packets = TPID (802.1Q)  
        int eType = default(0x88B8); // GOOSE
        int tci = default(0x8000); // If priority is not configured, the default value according the standard (part 8-1) for GOOSE
        int vid = default(1);
        int priority = default(1);
        double timeStamp = default(0);     
        double startTime @unit(s) = default(1s);  // time of sending the first packet
        double stopTime @unit(s) = default(0);  // time of finish sending, 0 means forever
        volatile double sendInterval @unit(s);  // interval between sending bursts
        volatile int numPacketsPerBurst = default(1);  // number of packets to send per burst (packets within a burst are sent at the same simulation time)
        volatile int packetLength @unit(B);  // length of packets to send
        @display("i=block/app");
        @signal[sentPk](type=cPacket);
        @signal[rcvdPk](type=cPacket);
        @signal[rcvdTrip1A](type=cPacket);        
        @statistic[rcvdPk](title="packets received"; source=rcvdPk; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
        @statistic[sentPk](title="packets sent"; source=sentPk; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
        @statistic[endToEndDelay](title="end-to-end delay"; source="messageAge(rcvdPk)"; unit=s; record=histogram,vector; interpolationmode=none);
        @statistic[eteTrip1A](title="eteTrip1A"; source="messageAge(rcvdTrip1A)"; unit=s; record=histogram,vector; interpolationmode=none);        
    gates:
        input in @labels(Ieee802Ctrl/up);
        output out @labels(Ieee802Ctrl/down);
}
