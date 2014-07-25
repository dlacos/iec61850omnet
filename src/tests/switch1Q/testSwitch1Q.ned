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

package iec61850model.tests.switch1Q;

import iec61850model.devices.Ied;
import iec61850model.devices.Switch;

import iec61850model.linklayer.ieee8021QConfigurator.Ieee8021QConfigurator;
import inet.nodes.inet.StandardHost;
import ned.DatarateChannel;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
//
// TODO documentation
//
channel eth100Mbps extends DatarateChannel
{
    datarate = 100Mbps;
}
//
// TODO auto-generated type
//
network Star
{
    @display("bgb=438,271");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            parameters:
                dumpAddresses = true;
                @display("p=92,29");
        }
        ied: Ied {
            @display("p=95,229");
        }
        ied1: Ied {
            @display("p=196,232");
        }
        ied2: Ied {
            @display("p=370,225");
        }
        ied3: Ied {
            @display("p=270,232");
        }
        switch: Switch {
            @display("p=245,76");
        }
        switch1: Switch {
            @display("p=163,159");
        }
        switch2: Switch {
            @display("p=317,158");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=80,94;is=s");
        }
        server: StandardHost {
            @display("p=367,54");
        }
    connections:
        switch.ethg++ <--> eth100Mbps <--> switch1.ethg++;
        switch.ethg++ <--> eth100Mbps <--> switch2.ethg++;
        switch1.ethg++ <--> eth100Mbps <--> ied.ethg;
        switch1.ethg++ <--> eth100Mbps <--> ied1.ethg;
        switch2.ethg++ <--> eth100Mbps <--> ied3.ethg;
        switch2.ethg++ <--> eth100Mbps <--> ied2.ethg;
        switch.ethg++ <--> eth100Mbps <--> server.ethg++;
}
