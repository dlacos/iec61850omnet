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
// @author David L. Acosta M. dlacos@gteccom.uff.br 

package iec61850model.simulations.substations;
import iec61850model.devices.Ied;
import iec61850model.devices.Switch;
import iec61850model.electricSubstation.FeederBay;
import iec61850model.electricSubstation.TransformerBay;
import iec61850model.linklayer.ieee8021QConfigurator.Ieee8021QConfigurator;
import iec61850model.nodes.ethernet.EnhancedSwitch;
import iec61850model.nodes.iec61850.ied.GenericIED;
import iec61850model.nodes.iec61850.ied.MergingUnit;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.nodes.inet.StandardHost;
import ned.DatarateChannel;
//import inet.linklayer.channels.MyThroughputMeteringChannel;
import inet.linklayer.channels.ProgramedFailureDataRateChannel;

channel Channel extends DatarateChannel
{
    datarate = 10Mbps;
}

network StarStar
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
        transformerBay[nT]: TransformerBay {
            @display("p=192,135,r");
        }
        workstation: StandardHost {
            parameters:
                numTcpApps = 1;
                @display("p=377,207");
        }
        server: Ied {
            @display("p=358,270");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=73,115");
        }
    connections:
        for i=0..nF-1 {
            switch.ethg++ <--> Channel <--> feederBay[i].eth;
        }
        for i=0..nT-1 {
            switch.ethg++ <--> Channel <--> transformerBay[i].eth;
        }
        //workstation.ethg++ <--> Channel <--> switch.ethg++;
        server.ethg <--> Channel <--> switch.ethg++;
}
//
// TODO documentation
//
network RingStar
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

            @display("p=453,187");
        }
        server: Ied {
            @display("p=448,267");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=62,120");
        }
    connections:
        //1. Connecting the ends according:
        //Connecting de ring StationSwitch-FeederSwitches-TransformerSwitches-StationSwitch
        //If there is at least 1 Feeder Bay: 
        switch.ethg++ <--> Channel <--> feederBay[0].eth if nF>0;
        feederBay[nF-1].eth2 <--> ProgramedFailureDataRateChannel {  failureAt = "19s"; recoveryAt = "180s"; datarate = 10Mbps; } <--> transformerBay[0].eth if nF>0 && nT>0;
        transformerBay[nT-1].eth2 <--> Channel <--> switch.ethg++ if nF>0 && nT>0;

        //If no Feeder bay then the ring will be StationSwitch-TransformerSwitches-StationSwitch
        switch.ethg++ <--> Channel <--> transformerBay[0].eth if nF==0 && nT>0;
        transformerBay[nT-1].eth2 <--> Channel <--> switch.ethg++ if nF==0 && nT>0;

        //If no Transformer bay then the ring will be StationSwitch-FeederSwitches-StationSwitch

        switch.ethg++ <--> Channel <--> feederBay[0].eth if nT==0 && nF>0;

        //If ... another kind of bay? TODO

        //2.Connecting rest ofthe ring 
        for i=0..nF-2 {
            feederBay[i].eth2 <--> Channel <--> feederBay[i+1].eth if nF>0;
        }
        for i=0..nT-2 {
            transformerBay[i].eth2 <--> Channel <--> transformerBay[i+1].eth if nT>0;
        }
        //switch.ethg++ <--> Channel <--> workstation.ethg++;
        server.ethg <--> Channel <--> switch.ethg++;
}

//
// TODO documentation
//
network T1
{
    submodules:
        S1: EnhancedSwitch {
            @display("p=200,59");
        }
        breaker1: GenericIED {
            @display("p=72,47");
        }
        breaker2: GenericIED {
            @display("p=77,107");
        }
        control1: GenericIED {
            @display("p=168,157");
        }
        mu1: MergingUnit {
            @display("p=314,67");
        }
        control2: GenericIED {
            @display("p=232,157");
        }
    connections:
        S1.ethg++ <--> breaker1.ethg;
        S1.ethg++ <--> breaker2.ethg;
        S1.ethg++ <--> control1.ethg;
        S1.ethg++ <--> mu1.ethg;
        S1.ethg++ <--> control2.ethg;
}

//
// TODO documentation
//
network S1
{
    @display("bgb=307,197");
    submodules:
        breaker1: GenericIED {
            @display("p=54,82");
        }
        control1: GenericIED {
            @display("p=155,136");
        }
        mu1: MergingUnit {
            @display("p=255,80");
        }
        S1: EnhancedSwitch {
            @display("p=152,68");
        }
    connections:
        S1.ethg++ <--> breaker1.ethg;
        S1.ethg++ <--> control1.ethg;
        S1.ethg++ <--> mu1.ethg;
        
}

