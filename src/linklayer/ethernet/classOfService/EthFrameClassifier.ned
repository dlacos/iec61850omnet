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

package iec61850model.linklayer.ethernet.classOfService;

//
// TODO auto-generated module
//
simple EthFrameClassifier
{
    parameters:
        bool enablePriority @display("i=block/classifier") = default(false);
        @display("i=block/classifier");
    gates:
        input in;
        output p7;
        output p6;
        output p5;
        output p4;
        output p3;
        output p2;
        output p1;
        output p0;
        //output defaultOut;
}
