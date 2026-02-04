`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:23:09 11/09/2023 
// Design Name: 
// Module Name:    EXT26 
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
module EXT26(
    input [25:0] index,
    input [31:0] PC,
    output [31:0] index32
    );

assign index32 = {{2{1'b0}},{PC[31:28]},{index}};

endmodule
