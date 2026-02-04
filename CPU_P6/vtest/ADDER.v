`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:08:54 11/09/2023 
// Design Name: 
// Module Name:    ADDER 
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
module ADDER(
    input [31:0] PCplus4,
    input [31:0] addressRest,
    output [31:0] expectedAddress
    );

assign expectedAddress = PCplus4+addressRest;

endmodule
