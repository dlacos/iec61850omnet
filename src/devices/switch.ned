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

package iec61850model.devices;

import iec61850model.basic.SwitchLayer;
import iec61850model.basic.Table8021Q;
import inet.base.NotificationBoard;
import inet.linklayer.IEtherMAC;
import inet.linklayer.IMACRelayUnit;
import inet.linklayer.IOutputQueue;
//import inet.linklayer.ethernet.EtherQoSQueue;
import inet.linklayer.ethernet.IEtherEncap;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;


module Switch
{
    parameters:
        @node();
        @labels(node,ethernet-node);
        @display("i=old/switch2;bgb=278,338");
        string table8021q = default("");
        bool csmacdSupport = default(true);  // by default use CSMA/CD
        //bool use8021Q = default(false);
        string macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        string queueType = default("DropTailQueue");
        //string queueType = default("DropTailQoSQueue");
        string relayUnitType = default("MACRelayUnitSTPNP"); // type of the ~IMACRelayUnit; currently possible
                                                          // values are ~MACRelayUnitNP ~MACRelayUnitPP ~MACRelayUnitSTPNP and ~MACRelayUnitModified 
    gates:
        inout ethg[] @labels(EtherFrame-conn);
    submodules:
        interfaceTable: InterfaceTable {
            @display("p=47,40");
        }
        notificationBoard: NotificationBoard {
            @display("p=45,126");
        }
        //        table8021Q: Table8021Q {
        //            parameters:            
        //                tableFileName = table8021q;
        //            	@display("p=47,125");
        //}
        eth[sizeof(ethg)]: <macType> like IEtherMAC {
            parameters:
                promiscuous = true;
                txQueueLimit = 5000;
                //queueModule = "queue[sizeof(ethg)]";                
                @display("p=58,288,r;q=txQueue");
            	//queueModule = (queueType == "" ? "" : "queue");
        }
        relay: <relayUnitType> like IMACRelayUnit {
            parameters:
                @display("p=228,108");
                //use8021Q = false;
            gates:
                lowerLayerIn[sizeof(ethg)];
                lowerLayerOut[sizeof(ethg)];
        }
    connections:
        for i=0..sizeof(ethg)-1 {
            eth[i].upperLayerIn <-- relay.lowerLayerOut[i];
            eth[i].upperLayerOut --> relay.lowerLayerIn[i];
            eth[i].phys <--> ethg[i];
        }
}
