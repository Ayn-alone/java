`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:58:45 11/02/2023 
// Design Name: 
// Module Name:    EXT 
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
module EXT16(
    input [15:0] imm,
    input extop,
    output [31:0] imm32
    );
wire [31:0] sigenedExtend;
wire [31:0] zeroExtend;

assign sigenedExtend = {{16{imm[15]}},imm};
assign zeroExtend = {{16{1'b0}},imm};
assign imm32 = (extop==0) ? zeroExtend
                :           sigenedExtend;
endmodule
