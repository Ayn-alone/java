`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:06:29 11/03/2023 
// Design Name: 
// Module Name:    ALU 
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
module ALU(
    input [31:0] read1,
    input [31:0] read2,
    input [4:0] aluop,
    output [31:0] aluData
    );
wire [31:0] ADD;
wire [31:0] SUB;
wire [31:0] OR;
wire [31:0] LU;
wire [31:0] AND;
wire [31:0] SLT;
wire [31:0] SLTU;


assign ADD = read1+read2;
assign SUB = read1-read2;
assign AND = read1&read2;
assign OR  = read1|read2;
assign LU  = read2<<16;
assign SLT = $signed(read1) < $signed(read2);
assign SLTU= $unsigned(read1) < $unsigned(read2); 

assign aluData = (aluop==0) ? ADD
                :(aluop==1) ? SUB
                :(aluop==2) ? AND
                :(aluop==3) ? OR
                :(aluop==4) ? LU
                :(aluop==5) ? SLT
                :(aluop==6) ? SLTU
                : ADD;
endmodule
