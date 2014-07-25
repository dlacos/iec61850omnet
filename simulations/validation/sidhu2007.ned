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

package iec61850model.simulations.validation;

import iec61850model.linklayer.ieee8021QConfigurator.Ieee8021QConfigurator;
import iec61850model.nodes.Server;
import iec61850model.nodes.ethernet.EnhancedSwitch;
import iec61850model.nodes.iec61850.ied.GenericIED;
import iec61850model.sas.StarZone;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import ned.DatarateChannel;
import iec61850model.sas.C;

//
// TODO auto-generated type
//

//channel Channel extends DatarateChannel
//{
//    datarate = 10Mbps;
//    delay = 0.000000033s; //10m fiber
//}

network Sidhu2007
{
    @display("bgb=461,318");
    submodules:
        iPv4NetworkConfigurator: IPv4NetworkConfigurator {
            parameters:
                dumpAddresses = true;
                @display("p=89,37");
        }
        switch: EnhancedSwitch {
            @display("p=287,168");
        }
        server: Server {
            @display("p=407,154;i=device/server");
        }

        T[2]: StarZone {
            parameters:
                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
                numBkIED = default(2); // number of Breaker IEDs on the substation section            
                @display("p=292,52,r");
        }
        //        T[1]: StarZone {
        //            parameters:
        //                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
        //                numBkIED = default(2); // number of Breaker IEDs on the substation section                        
        //                @display("p=242,64");
        //        }
        F[6]: StarZone {
            parameters:
                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
                numBkIED = default(1); // number of Breaker IEDs on the substation section                        
                @display("p=51,120,m,3");
        }
        //        F[1]: StarZone {
        //            parameters:
        //                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
        //                numBkIED = default(1); // number of Breaker IEDs on the substation section                        
        //                @display("p=159,158");
        //        }
        //        F[2]: StarZone {
        //            parameters:
        //                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
        //                numBkIED = default(1); // number of Breaker IEDs on the substation section                        
        //                @display("p=169,218");
        //        }
        //        F[3]: StarZone {
        //            parameters:
        //                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
        //                numBkIED = default(1); // number of Breaker IEDs on the substation section                        
        //                @display("p=205,254");
        //        }
        //        F[4]: StarZone {
        //            parameters:
        //                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
        //                numBkIED = default(1); // number of Breaker IEDs on the substation section                        
        //                @display("p=265,272");
        //        }
        //        F[5]: StarZone {
        //            parameters:
        //                numPCIED = default(2); // number of Protection & Control IEDs on the substation section
        //                numBkIED = default(1); // number of Breaker IEDs on the substation section                        
        //                @display("p=317,274");
        //        }
        S[1]: StarZone {
            parameters:
                numPCIED = default(1); // number of Protection & Control IEDs on the substation section
                numBkIED = default(1); // number of Breaker IEDs on the substation section                        
                @display("p=388,251");
        }
        workstation: Server {
            @display("p=384,90;i=device/pc");
        }
        ieee8021QConfigurator: Ieee8021QConfigurator {
            @display("p=86,267;is=s");
        }
    connections:
        switch.ethg++ <--> C <--> server.ethg;
        switch.ethg++ <--> C <--> T[0].eth;
        switch.ethg++ <--> C <--> T[1].eth;
        switch.ethg++ <--> C <--> F[0].eth;
        switch.ethg++ <--> C <--> F[1].eth;
        switch.ethg++ <--> C <--> F[2].eth;
        switch.ethg++ <--> C <--> F[3].eth;
        switch.ethg++ <--> C <--> F[4].eth;
        switch.ethg++ <--> C <--> F[5].eth;
        switch.ethg++ <--> C <--> S[0].eth;
        switch.ethg++ <--> C <--> workstation.ethg;
}
