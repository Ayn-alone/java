`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:13:42 11/09/2023 
// Design Name: 
// Module Name:    PCsel 
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
module PCsel(
    input [31:0] jal32,
    input [31:0] jr32,
    input [31:0] beq32,
    input [31:0] PCplus4,
    input jumpJudge,
    input isjal,
    input isjr,
    input isbeq,
    output [31:0] newPC
    );
wire [31:0] prePC;
assign prePC = (isjal==1&&isjr==0&&isbeq==0)               ? jal32
            :  (isjal==0&&isjr==1&&isbeq==0)               ? jr32
            :  (isjal==0&&isjr==0&&isbeq==1&&jumpJudge==1) ? beq32
            :                                              PCplus4;
assign newPC = (prePC-32'h00003000)%32'h00010000+32'h00003000;
endmodule
