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

package iec61850model.tests.iedSwitchTest;

import iec61850model.devices.Ied;
import iec61850model.devices.IedSwitch;
import iec61850model.linklayer.ieee8021QConfigurator.Ieee8021QConfigurator;
import iec61850model.nodes.ethernet.EnhancedSwitch;
import iec61850model.nodes.iec61850.ied.GenericIED;
import iec61850model.nodes.iec61850.ied.SwitchingIED;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import ned.DatarateChannel;

channel C extends DatarateChannel
{
    datarate = 100Mbps;
}

//
// TODO auto-generated type
//
network IedSwitchTest
{
    @display("bgb=500,316");
    submodules:
        s1: EnhancedSwitch {
            @display("p=278,83");
        }
        s2: EnhancedSwitch {
            @display("p=187,165");
        }
        s3: EnhancedSwitch {
            @display("p=379,159");
        }
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=77,48");
        }
        ied1: SwitchingIED {
            @display("p=115,246");
        }
        //        ied24: SwitchingIED {
        //            @display("p=292,266");
        //        }
        //        ied1: GenericIED {
        //            @display("p=114,235");
        //        }
        ied2: GenericIED {
            @display("p=230,243");
        }
        ied3: GenericIED {
            @display("p=421,235");
        }

        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=82,114;is=s");
        }
    connections:
        s1.ethg++ <--> C <--> s2.ethg++;
        s1.ethg++ <--> C <--> s3.ethg++;
        ied2.ethg <--> C <--> s2.ethg++;
        s3.ethg++ <--> C <--> ied3.ethg;
        s2.ethg++ <--> C <--> ied1.ethg++;
}
