`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:42:16 12/03/2023 
// Design Name: 
// Module Name:    ALUResultSel 
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
module ALUResultSel(
    input [31:0] aluResult,
    input [31:0] maluResult,
    input aluSel,
    output [31:0] trueAluResult
    );

assign trueAluResult = (aluSel==1) ? maluResult : aluResult;

endmodule
