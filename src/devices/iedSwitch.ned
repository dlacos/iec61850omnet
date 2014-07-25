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
import iec61850model.basic.Dispatcher;
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

//
// TODO auto-generated type
//
module IedSwitch
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
            @display("p=68,205");
        }
        routingTable: RoutingTable {
            @display("p=70,128");
        }
        notificationBoard: NotificationBoard {
            @display("p=70,285");
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
                @display("p=308,223");
        }
        tcp: <tcpType> like ITCP {
            @display("p=308,141");
        }
        trip1A_a: Iec61850trafgen {
            parameters:
                //vid = 1;
                @display("p=145,62");
        }
        layer8021Q: Layer8021Q {
            @display("p=169,285");
        }
        mms: <default("TCPBasicClientApp")> like ITCPApp {
            parameters:
                @display("p=308,60");
        }
        IPburst: <ipBurstType> like IIPvXTrafficGenerator {
            @display("p=386,141");
        }
        trip1A_b: Iec61850trafgen {
            @display("p=221,64");
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
        layer8021Q.toEthApp_a --> trip1A_a.in;
        trip1A_a.out --> layer8021Q.fromEthApp_a;
        pcapper.upperOut --> encap.lowerLayerIn;
        mms.tcpOut --> tcp.appIn++;
        tcp.appOut++ --> mms.tcpIn;
        IPburst.ipOut --> networkLayer.udpIn;
        networkLayer.udpOut --> IPburst.ipIn;
        trip1A_b.out --> layer8021Q.fromEthApp_b;
        layer8021Q.toEthApp_b --> trip1A_b.in;
}
