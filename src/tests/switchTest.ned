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

package iec61850model.tests;
import iec61850model.devices.Ied;
import iec61850model.devices.Switch;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.nodes.ethernet.EtherSwitch;
import inet.nodes.inet.Router;
import inet.nodes.inet.StandardHost;

//
// TODO documentation
//
network SwitchTest
{
    @display("bgb=658,330");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            @display("p=90,52");
            config = xmldoc("config.xml");
        }
        ied1: Ied {
            @display("p=175,230");
        }
        ied3: Ied {
            @display("p=332,230");
        }
        ied2: Ied {
            @display("p=259,230");
        }
        ied4: Ied {
            @display("p=426,230");
        }
        host1: StandardHost {
            parameters:
                numTcpApps = 1;
                //tcpType = "TCP";
                numPingApps = default(1);
                @display("p=518,181");
        }
        router: Router {
            @display("p=518,52");
        }
        s2: Switch {
            @display("p=225,159");
        }
        s3: Switch {
            @display("p=363,159");
        }
        s1: Switch {
            @display("p=287,81");
        }
    connections:
        s1.ethg++ <--> eth100MbpsChannel <--> s2.ethg++;
        s1.ethg++ <--> eth100MbpsChannel <--> s3.ethg++;
        s2.ethg++ <--> eth100MbpsChannel <--> ied1.ethg;
        s3.ethg++ <--> eth100MbpsChannel <--> ied3.ethg;
        s2.ethg++ <--> eth100MbpsChannel <--> ied2.ethg;
        s3.ethg++ <--> eth100MbpsChannel <--> ied4.ethg;
        s3.ethg++ <--> eth100MbpsChannel <--> host1.ethg++;
        router.ethg++ <--> eth100MbpsChannel <--> s1.ethg++;
}
