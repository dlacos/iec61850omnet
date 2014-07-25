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

import iec61850model.devices.Ied;
import iec61850model.devices.Mu;
import iec61850model.devices.Switch;


module FeederBay
{
    parameters:
        int nPCIED = default(2); // number of Protection & Control IEDs on the substation
        int nBkIED = default(1); // number of Transformer Bays in the substation    
        @display("bgb=332,188;i=misc/building");
    gates:
        inout eth @labels(EtherFrame-conn);
        inout eth2 @labels(EtherFrame-conn) @loose;
    submodules:
        breaker[nBkIED]: Ied {
            @display("p=64,37,c");
        }
        control[nPCIED]: Ied {
            @display("p=124,154,r");
        }
        switch: Switch {
            @display("p=173,50");
        }
        mu: Mu {
            @display("p=259,72");
        }
    connections allowunconnected:
        for i=0..nPCIED-1 {
            switch.ethg++ <--> eth100MbpsChannel <--> control[i].ethg;
        }
        for i=0..nBkIED-1 {
            switch.ethg++ <--> eth100MbpsChannel <--> breaker[i].ethg;
        }
        //        switch.ethg++ <--> eth100MbpsChannel <--> breaker.ethg;
        //        switch.ethg++ <--> eth100MbpsChannel <--> control1.ethg;
        //        switch.ethg++ <--> eth100MbpsChannel <--> control2.ethg;
        switch.ethg++ <--> eth;
        switch.ethg++ <--> eth2;
        switch.ethg++ <--> eth100MbpsChannel <--> mu.ethg;
}
