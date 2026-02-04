`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:10:47 11/02/2023 
// Design Name: 
// Module Name:    PC 
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
module PC(
    input reset,
    input enable,
    input clk,
    input [31:0] newAddress,
    output reg [31:0] currentAddress
    );
initial begin
    currentAddress<=32'h00003000;
end
always @(posedge clk) begin
    if (reset==1) begin
        currentAddress<=32'h00003000;
    end
    else if (reset==0&&enable==0) begin
        currentAddress<=currentAddress;
    end
    else begin
        currentAddress<=newAddress;
    end
end

endmodule
