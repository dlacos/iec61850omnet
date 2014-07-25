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

package iec61850model.nodes.iec61850.ied;

import iec61850model.linklayer.Layer8021Q;
import iec61850model.linklayer.ethernet.classOfService.CoSQueue;
import iec61850model.nodes.iec61850.ied.applicationProfile.sampledValues.SVApp;
import iec61850model.util.Pcapper;
import inet.applications.ITCPApp;
import inet.base.NotificationBoard;
import inet.linklayer.IEtherMAC;
import inet.linklayer.IOutputQueue;
import inet.linklayer.ethernet.IEtherEncap;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.nodes.inet.NetworkLayer;
import inet.transport.ITCP;


//
// TODO auto-generated type
//
module MergingUnit
{
    parameters:
        bool csmacdSupport = default(true);  // by default use CSMA/CD
        string macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        string queueType = default("CoSQueue"); // DropTailQueue, DiffServQueue, or "" to use the internal queue
        //string tcpType = default(firstAvailable("TCP", "TCP_lwIP", "TCP_NSC", "TCP_None"));  // tcp implementation (e.g. ~TCP, ~TCP_lwIP, ~TCP_NSC) or ~TCPSpoof
        //string ipBurstType = default("IPvXTrafGen");
        //string tcpApp = default("MMSAppServer");
        @node();
        @display("bgb=354,560;i=device/device");
    gates:
        inout ethg @labels(EtherFrame-conn);
    submodules:
        interfaceTable: InterfaceTable {
            @display("p=292,380");
        }
        routingTable: RoutingTable {
            @display("p=292,293");
        }
        notificationBoard: NotificationBoard {
            @display("p=292,458");
        }
        queue: <queueType> like IOutputQueue {//CoSQueue if queueType != "" {
            parameters:
                //dataQueueType = queueType;
                @display("p=90,356;q=l2queue");
        }
        mac: <macType> like IEtherMAC {
            queueModule = (queueType == "" ? "" : "queue");
            @display("p=155,497;q=txQueue");
        }
        encap: <default("EtherEncap")> like IEtherEncap {
            @display("p=155,293");
        }
        pcapper: Pcapper {
            @display("p=155,425");
        }
        networkLayer: NetworkLayer {
            parameters:
                proxyARP = default(false);
                igmpType = default("IGMPv2");
                @display("p=265,153");
        }
        //        tcp: <tcpType> like ITCP {
        //            @display("p=242,222");
        //        }
        layer8021Q: Layer8021Q {
            @display("p=155,215");
        }
        //        mmsApp: <tcpApp> like ITCPApp {
        //            @display("p=243,133");
        //        }
        svApp: SVApp {
            @display("p=155,66");
        }
    //        udp: <paramName> like IUDP {
    //            @display("p=314,224");
    //        }
    connections allowunconnected:
        mac.upperLayerOut --> pcapper.lowerIn;
        encap.lowerLayerOut --> pcapper.upperIn if queueType == "";
        queue.out --> pcapper.upperIn if queueType != "";
        pcapper.lowerOut --> mac.upperLayerIn;
        encap.lowerLayerOut --> queue.in if queueType != "";
        mac.phys <--> ethg;
        encap.upperLayerOut --> layer8021Q.fromEncapLayer;
        layer8021Q.toEncapLayer --> encap.upperLayerIn;
        layer8021Q.toNetLayer --> networkLayer.ifIn++;
        networkLayer.ifOut++ --> layer8021Q.fromNetLayer;
        //        networkLayer.tcpOut --> tcp.ipIn;
        //        tcp.ipOut --> networkLayer.tcpIn;
        pcapper.upperOut --> encap.lowerLayerIn;
        //        mmsApp.tcpOut --> tcp.appIn++;
        //        tcp.appOut++ --> mmsApp.tcpIn;
        svApp.out --> layer8021Q.fromEthApp_a;
        layer8021Q.toEthApp_a --> svApp.in;
}
