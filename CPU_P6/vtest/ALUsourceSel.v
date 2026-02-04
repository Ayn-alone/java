`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:27:42 11/09/2023 
// Design Name: 
// Module Name:    ALUsource 
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
module ALUSel(
    input ALUSrc,
    input [31:0] RD2,
    input [31:0] ext32,
    output [31:0] alusource
    );

assign alusource = (ALUSrc==1) ? ext32 : RD2;

endmodule
