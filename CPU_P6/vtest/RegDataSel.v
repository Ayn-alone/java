`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:28:59 11/09/2023 
// Design Name: 
// Module Name:    RegDataSel 
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
module RegDataSel(
    input [31:0] MemData,
    input [31:0] AluData,
    input [31:0] PCplus8,
    input MemToReg,
    input isjal,
    output [31:0] RegData
    );

assign RegData = (MemToReg==1) ? MemData : (MemToReg==0&&isjal==1) ? PCplus8 : AluData;

endmodule
