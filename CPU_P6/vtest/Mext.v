`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:01:18 12/02/2023 
// Design Name: 
// Module Name:    Mext 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Mext(
    input [31:0] m_data_rdata,
    input [5:0] MmemMark,
    input [31:0] address,
    output [31:0] mdata
    );

wire [15:0] h1data;
wire [15:0] h2data;
wire [7:0] b1data;
wire [7:0] b2data;
wire [7:0] b3data;
wire [7:0] b4data;
wire [1:0] addr2;
/*
assign memMark = (opcode==sbop) ? 1
                :(opcode==shop) ? 2
                :(opcode==swop) ? 3
                :(opcode==lbop) ? 4
                :(opcode==lhop) ? 5
                :(opcode==lwop) ? 6
                :0;
*/

assign addr2 = address[1:0];
assign h2data = m_data_rdata[31:16];
assign h1data = m_data_rdata[15:0];
assign b4data = m_data_rdata[31:24];  
assign b3data = m_data_rdata[23:16];
assign b2data = m_data_rdata[15:8];
assign b1data = m_data_rdata[7:0];

assign mdata =     (MmemMark==4&&addr2==2'b00) ? {{24{b1data[7]}},b1data}
                :  (MmemMark==4&&addr2==2'b01) ? {{24{b2data[7]}},b2data}
                :  (MmemMark==4&&addr2==2'b10) ? {{24{b3data[7]}},b3data}
                :  (MmemMark==4&&addr2==2'b11) ? {{24{b4data[7]}},b4data}
                :  (MmemMark==5&&addr2[1]==0)  ? {{16{h1data[15]}},h1data}
                :  (MmemMark==5&&addr2[1]==1)  ? {{16{h2data[15]}},h2data}
                :  (MmemMark==6) ? m_data_rdata
                :0;
endmodule
