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

import iec61850model.applications.Iec61850trafgen;
import iec61850model.linklayer.Layer8021Q;
import iec61850model.util.Pcapper;
import inet.applications.ITCPApp;
import inet.applications.generic.IIPvXTrafficGenerator;
import inet.applications.tcpapp.TCPGenericSrvApp;
import inet.base.NotificationBoard;
import inet.linklayer.IEtherMAC;
import inet.linklayer.IOutputQueue;
import inet.linklayer.ethernet.EtherQoSQueue;
import inet.linklayer.ethernet.IEtherEncap;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.nodes.inet.NetworkLayer;
import inet.transport.ITCP;

//Generic Intelligent Electronic Device that uses a GOOSE Trafic Generator and MMS Server application.
module Ied
{
    parameters:
        bool csmacdSupport = default(true);  // by default use CSMA/CD
        string macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        string queueType = default("DropTailQueue"); // DropTailQueue, DiffServQueue, or "" to use the internal queue
        string tcpType = default(firstAvailable("TCP", "TCP_lwIP", "TCP_NSC", "TCP_None"));  // tcp implementation (e.g. ~TCP, ~TCP_lwIP, ~TCP_NSC) or ~TCPSpoof
        string ipBurstType = default("IPvXTrafGen");
        @node();
        @display("bgb=441,620;i=device/device");
    gates:
        inout ethg @labels(EtherFrame-conn);
    submodules:
        interfaceTable: InterfaceTable {
            @display("p=306,450");
        }
        routingTable: RoutingTable {
            @display("p=306,363");
        }
        notificationBoard: NotificationBoard {
            @display("p=306,528");
        }
        queue: EtherQoSQueue if queueType != "" {
            parameters:
                dataQueueType = queueType;
                @display("p=104,426;q=l2queue");
        }
        mac: <macType> like IEtherMAC {
            queueModule = (queueType == "" ? "" : "queue");
            @display("p=169,567;q=txQueue");
        }
        encap: <default("EtherEncap")> like IEtherEncap {
            @display("p=169,363");
        }
        pcapper: Pcapper {
            @display("p=169,495");
        }
        networkLayer: NetworkLayer {
            parameters:
                proxyARP = default(false);
                igmpType = default("IGMPv2");
                @display("p=277,217");
        }
        tcp: <tcpType> like ITCP {
            @display("p=277,135");
        }
        iec61850trafgen: Iec61850trafgen {
            parameters:
                //vid = 1;
                @display("p=169,54");
        }
        layer8021Q: Layer8021Q {
            @display("p=169,285");
        }
        mms: <default("TCPBasicClientApp")> like ITCPApp {
            parameters:
                @display("p=277,54");
        }
        IPburst: <ipBurstType> like IIPvXTrafficGenerator {
            @display("p=361,138");
        }
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
        networkLayer.tcpOut --> tcp.ipIn;
        tcp.ipOut --> networkLayer.tcpIn;
        layer8021Q.toEthApp_a --> iec61850trafgen.in;
        iec61850trafgen.out --> layer8021Q.fromEthApp_a;
        pcapper.upperOut --> encap.lowerLayerIn;
        mms.tcpOut --> tcp.appIn++;
        tcp.appOut++ --> mms.tcpIn;
        IPburst.ipOut --> networkLayer.udpIn;
        networkLayer.udpOut --> IPburst.ipIn;
}
