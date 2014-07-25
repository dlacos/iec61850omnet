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

package iec61850model.sas;
import ned.DatarateChannel;
//
// TODO documentation
//
channel C extends DatarateChannel
{
    datarate = 10Mbps;
    delay = 0.00000005s; //Propagation delay (aprox. 10m fiber)
    
}

channel eth1GbpsChannel extends DatarateChannel
{
    datarate = 1000Mbps;
}

//
// TODO documentation
//
channel FailureChannel extends DatarateChannel
{
    datarate = 1000Mbps;
}

//
// TODO documentation
//
channel eth100MbpsChannel extends DatarateChannel
{
    datarate = 100Mbps;
}

channel eth10MbpsChannel extends DatarateChannel
{
    datarate = 10Mbps;
}

