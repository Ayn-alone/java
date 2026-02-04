`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:20:35 11/08/2023 
// Design Name: 
// Module Name:    RegisterM 
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
module RegisterM(
    input clk,
    input reset, 
    input [4:0] RegSelectedIN,
    input [31:0] aluresultIN,
    input [31:0] RD2IN,
    input [31:0] PCplus8IN,
    input MemtoRegIN,
    input RegWriteIN,
    input MemWriteIN,
    input isjalIN,
    input [3:0] MTnewIN,
    input [31:0] instrIN,
    input [31:0] PCIN,
    input [5:0] EmemMark,
    output reg [5:0] MmemMark,
    output reg [31:0] PCOUT,
    output reg [31:0] instrOUT, 
    output reg [3:0] MTnewOUT,
    output reg MemtoRegOUT,
    output reg RegWriteOUT,
    output reg MemWriteOUT,
    output reg isjalOUT,
    output reg [31:0] PCplus8OUT,
    output reg [31:0] RD2OUT,  
    output reg [4:0] RegSelectedOUT,
    output reg [31:0] aluresultOUT
    );

initial begin
    MemtoRegOUT <= 1'd0;
    RegWriteOUT <= 1'd0;
    MemWriteOUT <= 1'd0;
    isjalOUT <= 1'd0;
    RegSelectedOUT <= 5'd0;
    aluresultOUT <= 32'd0;
    RD2OUT <= 32'd0;
    PCplus8OUT <= 32'd0;
    MTnewOUT <= 4'd0;
    instrOUT <= 32'd0;
    PCOUT <= 32'h00003000;
    MmemMark <= 0;
end

always @(posedge clk) begin
    if(reset==1) begin
        MemtoRegOUT <= 1'd0;
        RegWriteOUT <= 1'd0;
        MemWriteOUT <= 1'd0;
        isjalOUT <= 1'd0;
        RegSelectedOUT <= 5'd0;
        aluresultOUT <= 32'd0;
        RD2OUT <= 32'd0;
        PCplus8OUT <= 32'd0;
        MTnewOUT <= 4'd0;
        instrOUT <= 32'd0;
        PCOUT <= 32'h00003000;
        MmemMark <= 0;
    end
    else begin
        RegSelectedOUT <= RegSelectedIN;
        aluresultOUT <= aluresultIN;
        RD2OUT <= RD2IN;
        PCplus8OUT <= PCplus8IN;
        MemtoRegOUT <= MemtoRegIN;
        RegWriteOUT <= RegWriteIN;
        MemWriteOUT <= MemWriteIN;
        isjalOUT <= isjalIN;
        MTnewOUT <= MTnewIN;
        instrOUT <= instrIN;
        PCOUT <= PCIN;
        MmemMark <= EmemMark;
    end
end
endmodule
