`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:07:44 11/08/2023 
// Design Name: 
// Module Name:    RegisterD 
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
module RegisterD(
    input clk, 
    input reset,
    input enable,
    input [31:0] instrIN,
    input [31:0] pcIN,
    input [31:0] PCplus4IN, 
    input [3:0] TuseIN,
    input [3:0] DTnewIN,
    output reg [31:0] pcOUT,
    output reg [3:0] DTnewOUT,
    output reg [3:0] TuseOUT,
    output reg [31:0] instrOUT,
    output reg [31:0] PCplus4OUT
    );

initial begin
    instrOUT <= 32'd0;
    PCplus4OUT <= 32'd0;
    TuseOUT <= 4'd0;
    DTnewOUT <= 4'd0;
    pcOUT <= 32'h00003000;
end

always @(posedge clk) begin
    if (reset==1) begin
        instrOUT <= 0;
        pcOUT <= 32'h00003000;
        PCplus4OUT <= 0;
        TuseOUT <= 0;
        DTnewOUT <= 0;
    end
    else if (reset==0&&enable==0) begin
        instrOUT <= instrOUT;
        PCplus4OUT <= PCplus4OUT;
        TuseOUT <= TuseOUT;
        DTnewOUT <= DTnewOUT;
        pcOUT <= pcOUT;
    end
    else begin
        instrOUT <= instrIN;
        PCplus4OUT <= PCplus4IN;
        TuseOUT <= TuseIN;
        DTnewOUT <= DTnewIN;
        pcOUT <= pcIN;
    end
end

endmodule