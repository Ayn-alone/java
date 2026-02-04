`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:10:38 11/09/2023 
// Design Name: 
// Module Name:    ShiftLeft2 
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
module ShiftLeft2(
    input [31:0] ext32,
    output [31:0] beqExpected
    );

assign beqExpected = ext32<<2;
endmodule
