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

package iec61850model.tests.genericIedTest;

import iec61850model.devices.Switch;
import iec61850model.nodes.Server;
import iec61850model.nodes.iec61850.ied.GenericIED;
import iec61850model.nodes.iec61850.ied.MergingUnit;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import ned.DatarateChannel;

channel Channel extends DatarateChannel
{
    datarate = 100Mbps;
}


//
// TODO auto-generated type
//
network StarStar
{
    submodules:
        genericIED: GenericIED {
            @display("p=84,207");
        }
        switch: Switch {
            @display("p=241,74");
        }
        switch1: Switch {
            @display("p=168,125");
        }
        switch2: Switch {
            @display("p=313,130");
        }
        genericIED1: GenericIED {
            @display("p=195,208");
        }
        genericIED2: GenericIED {
            @display("p=326,205");
        }
        genericIED3: GenericIED {
            @display("p=426,203");
        }
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=74,43");
        }
        mu: MergingUnit {
            @display("p=420,131");
        }
        workstation: Server {
            @display("p=352,48");
        }
    connections:
        switch.ethg++ <--> Channel <--> switch1.ethg++;
        switch.ethg++ <--> Channel <--> switch2.ethg++;
        switch1.ethg++ <--> Channel <--> genericIED.ethg;
        switch1.ethg++ <--> Channel <--> genericIED1.ethg;
        switch2.ethg++ <--> Channel <--> genericIED2.ethg;
        switch2.ethg++ <--> Channel <--> genericIED3.ethg;
        mu.ethg <--> Channel <--> switch2.ethg++;
        switch.ethg++ <--> Channel <--> workstation.ethg;
}
