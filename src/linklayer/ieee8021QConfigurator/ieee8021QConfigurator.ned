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

package iec61850model.linklayer.ieee8021QConfigurator;

//
// TODO auto-generated module
// Used by Switch1Q
simple Ieee8021QConfigurator
{
    parameters:
        //xml config = default(xml("<config><interface hosts='**' address='10.x.x.x' netmask='255.x.x.x'/></config>")); // XML configuration parameters for IP address assignment and adding manual routes
        int numVLANs = default(0); // Virtual LANs. 0 if not used. Not implemented yet   
        int numMulticastGroups = default(0); // Multicast Groups. 0 if not used. Not implemented yet

        double agingTime @unit("s") = default(50s);
        string tableFileName = default("");
        bool verbose = default(false);

        //bool useMCast = default(false); // Use Multicast groups?
        //bool useVLans = default(false); // Use VLANs?
        //bool dumpTopology = default(false);  // print extracted network topology to the module output
        //bool dumpLinks = default(false);     // print recognized network links to the module output
        //bool dumpAddresses = default(false); // print assigned IP addresses for all interfaces to the module output
        //bool dumpRoutes = default(false);    // print configured and optimized routing tables for all nodes to the module output
        //string dumpConfig = default("");     // write configuration into the given config file that can be fed back to speed up subsequent runs (network configurations)
        @display("i=block/cogwheel");
}
