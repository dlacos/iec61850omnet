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

package iec61850model.tests.substationSidhu2007;

import iec61850model.devices.Ied;
import iec61850model.devices.Switch;
import iec61850model.electricSubstation.StationSection;
import iec61850model.linklayer.ieee8021QConfigurator.Ieee8021QConfigurator;
import iec61850model.nodes.iec61850.ied.GenericIED;
import inet.nodes.inet.StandardHost;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import ned.DatarateChannel;


channel Channel extends DatarateChannel
{
    datarate = 100Mbps;
}

//
// TODO auto-generated type
//
network SubstationSidhu2007
{
    @display("bgb=516,334");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            parameters:
                dumpAddresses = true;
                @display("p=84,49");
        }
        stationSwitch: Switch {
            @display("p=312,173");
        }
        T1: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(2); // number of Breaker IEDs on the substation section
                @display("p=325,48");
        }
        T2: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(2); // number of Breaker IEDs on the substation section            
                @display("p=252,56");
        }
        S1: StationSection {
            parameters:
                nPCIED = default(1); // number of Protection & Control IEDs on the substation section
                nBkIED = default(1); // number of Breaker IEDs on the substation section
                @display("p=174,93");
        }
        F1: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(1); // number of Breaker IEDs on the substation section
                @display("p=140,172");
        }
        F2: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(1); // number of Breaker IEDs on the substation section
                @display("p=161,253");
        }
        F3: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(1); // number of Breaker IEDs on the substation section
                @display("p=236,286");
        }
        F4: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(1); // number of Breaker IEDs on the substation section            
                @display("p=321,289");
        }
        F5: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(1); // number of Breaker IEDs on the substation section             
                @display("p=402,285");
        }
        F6: StationSection {
            parameters:
                nPCIED = default(2); // number of Protection & Control IEDs on the substation section
                nBkIED = default(1); // number of Breaker IEDs on the substation section             
                @display("p=468,235");
        }
        //        workstation: StandardHost {
        //            parameters:
        //                numTcpApps = 1;
        //                tcpType = "TCP";
        //                @display("p=412,69");
        //        }
        //        serverS: StandardHost {
        //            parameters:
        //                numTcpApps = 1;
        //                tcpType = "TCP";
        //                @display("p=468,141");
        //        }
        server: GenericIED {
            @display("p=406,131;i=device/pc");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            parameters:
                //tableFileName = "table8021q.txt"
                @display("p=78,111;is=s");
        }
    connections:
        stationSwitch.ethg++ <--> Channel <--> T1.eth;
        stationSwitch.ethg++ <--> Channel <--> T2.eth;
        stationSwitch.ethg++ <--> Channel <--> S1.eth;
        stationSwitch.ethg++ <--> Channel <--> F1.eth;
        stationSwitch.ethg++ <--> Channel <--> F2.eth;
        stationSwitch.ethg++ <--> Channel <--> F3.eth;
        stationSwitch.ethg++ <--> Channel <--> F4.eth;
        stationSwitch.ethg++ <--> Channel <--> F5.eth;
        stationSwitch.ethg++ <--> Channel <--> F6.eth;
        //stationSwitch.ethg++ <--> Channel <--> server.ethg++;
        //stationSwitch.ethg++ <--> Channel <--> workstation.ethg++;
        server.ethg <--> Channel <--> stationSwitch.ethg++;
}
