`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:12:19 11/09/2023 
// Design Name: 
// Module Name:    CMP 
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
module CMP(
    input isbeq,
    input isjal,
    input isjr,
    input equal,
    output jumpJudge,
    input [31:0] RD1,
    input [31:0] RD2
    );

assign jumpJudge = (isbeq==1&&(RD1==RD2)&&(equal==1)) ? 1
                :  (isbeq==1&&(RD1!=RD2)&&(equal==0)) ? 1
                :  0;  

endmodule
