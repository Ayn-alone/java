`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:19:57 11/09/2023 
// Design Name: 
// Module Name:    RegSel 
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
module RegSel(
    input [4:0] rt,
    input [4:0] rd,
    input aluSel,
    input isjal,
    input RegDst,
    input jumpjudge,
    output [4:0] RegSelected
    );

assign RegSelected =  (isjal==1)                        ? 31
                    : (isjal==0&&aluSel==0&&RegDst==0)  ? rt
                    : (isjal==0&&aluSel==0&&RegDst==1)  ? rd
                    : (isjal==0&&aluSel==1&&RegDst==0)  ? 0
                    : (isjal==0&&aluSel==1&&RegDst==1)  ? rd
                    : 0;

endmodule
