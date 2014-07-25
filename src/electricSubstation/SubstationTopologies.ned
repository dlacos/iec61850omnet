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

package iec61850model.electricSubstation;

import iec61850model.devices.Switch;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.nodes.inet.StandardHost;

//
// TODO auto-generated type
//
moduleinterface ISubstationTopology
{
    parameters:
        int nF; // number of Feeder Bays in the substation
        int nT; // number of Transformer Bays in the substation
        @display("bgb=332,188;i=misc/building");
}

//
// TODO auto-generated type
//
module Star like ISubstationTopology
{
    parameters:
        int nF = default(4); // number of Feeder Bays in the substation
        int nT = default(2); // number of Transformer Bays in the substation
        @display("bgb=552,402");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            parameters:
                dumpAddresses = true;
                @display("p=85,39");
        }
        switch: Switch {
            @display("p=273,217");
        }
        feederBay[nF]: FeederBay {
            @display("p=132,343,r");
        }
//        feederBay2: FeederBay {
//            @display("p=231,343");
//        }

        transformerBay[nT]: TransformerBay {
            @display("p=192,135,r");
        }
        workstation: StandardHost {
            parameters:
                numTcpApps = 1;
                //tcpType = "TCP";
                //tcpType = default(firstAvailable("TCP", "TCP_lwIP", "TCP_NSC", "TCP_None"));  // tcp implementation (e.g. ~TCP, ~TCP_lwIP, ~TCP_NSC) or ~TCPSpoof
                //tcpApp[0].typename = "TCPSessionApp";
                //IPForward = default(false);
                //numPingApps = 1;
                @display("p=377,207");
        }
    //        feederBay3: FeederBay {
    //            @display("p=322,343");
    //        }
    connections:
        for i=0..nF-1 {
            switch.ethg++ <--> eth100MbpsChannel <--> feederBay[i].eth;
        }
        for i=0..nT-1 {
            switch.ethg++ <--> eth100MbpsChannel <--> transformerBay[i].eth;
        }
        workstation.ethg++ <--> eth100MbpsChannel <--> switch.ethg++;
}
//
// TODO documentation
//
module Ring like ISubstationTopology
{
    parameters:
        int nF = default(4); // number of Feeder Bays in the substation
        int nT = default(2); // number of Transformer Bays in the substation
        @display("bgb=552,402");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=85,39");
        }
        switch: Switch {
            @display("p=361,229");
        }
        feederBay[nF]: FeederBay {
            @display("p=139,271,r");
        }
        transformerBay[nT]: TransformerBay {
            @display("p=178,98,r");
        }
        workstation: StandardHost {
            numTcpApps = 1;
            tcpType = "TCP";

            @display("p=454,219");
        }
    connections:
        //1. Connecting the ends according:
        //Connecting de ring StationSwitch-FeederSwitches-TransformerSwitches-StationSwitch
        //If there is at least 1 Feeder Bay: 
        switch.ethg++ <--> eth100MbpsChannel <--> feederBay[0].eth if nF>0;
        feederBay[nF-1].eth2 <--> eth100MbpsChannel <--> transformerBay[0].eth if nF>0 && nT>0;
        transformerBay[nT-1].eth2 <--> eth100MbpsChannel <--> switch.ethg++ if nF>0 && nT>0;

        //If no Feeder bay then the ring will be StationSwitch-TransformerSwitches-StationSwitch
        switch.ethg++ <--> eth100MbpsChannel <--> transformerBay[0].eth if nF==0 && nT>0;
        transformerBay[nT-1].eth2 <--> eth100MbpsChannel <--> switch.ethg++ if nF==0 && nT>0;

        //If no Transformer bay then the ring will be StationSwitch-FeederSwitches-StationSwitch

        switch.ethg++ <--> eth100MbpsChannel <--> feederBay[0].eth if nT==0 && nF>0;

        //If ... another kind of bay? TODO

        //2.Connecting rest ofthe ring 
        for i=0..nF-2 {
            feederBay[i].eth2 <--> eth100MbpsChannel <--> feederBay[i+1].eth if nF>0;
        }
        for i=0..nT-2 {
            transformerBay[i].eth2 <--> eth100MbpsChannel <--> transformerBay[i+1].eth if nT>0;
        }
        switch.ethg++ <--> eth100MbpsChannel <--> workstation.ethg++;
}
