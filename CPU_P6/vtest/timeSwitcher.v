`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:04:34 11/10/2023 
// Design Name: 
// Module Name:    timeSwitcher 
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
module timeSwitcher(
    input [3:0] originalT,
    output [3:0] nowT
    );

assign nowT = (originalT>0) ? originalT-1 : 0; 

endmodule
