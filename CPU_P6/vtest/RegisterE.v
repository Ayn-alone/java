`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:16:08 11/08/2023 
// Design Name: 
// Module Name:    RegisterE 
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
module RegisterE(
    input clk,
    input reset,
    input Ereset,
    input [4:0] Drs,
    input [4:0] Drt,
    input [4:0] RegSelectedIN,
    input [31:0] RD1IN,
    input [31:0] RD2IN,
    input [31:0] ext32IN,
    input [31:0] PCplus8IN,
    input ALUSrcIN,
    input MemtoRegIN,
    input RegWriteIN,
    input MemWriteIN,
    input isjalIN,
    input [4:0] ALUOPIN,
    input [3:0] ETnewIN,
    input [31:0] instrIN,
    input [31:0] PCIN,
    input [5:0] DmemMark,
    input aluSel,
    output reg EaluSel,
    output reg [5:0] EmemMark,
    output reg [31:0] PCOUT,
    output reg [4:0] Ers,
    output reg [4:0] Ert,
    output reg [31:0] instrOUT, 
    output reg [3:0] ETnewOUT,
    output reg ALUSrcOUT,
    output reg MemtoRegOUT,
    output reg RegWriteOUT,
    output reg MemWriteOUT,
    output reg isjalOUT,
    output reg [4:0] ALUOPOUT,
    output reg [31:0] PCplus8OUT,
    output reg [31:0] ext32OUT, 
    output reg [4:0] RegSelectedOUT,
    output reg [31:0] RD1OUT,
    output reg [31:0] RD2OUT
    );

initial begin
    ALUSrcOUT <= 1'd0;
    MemtoRegOUT <= 1'd0;
    RegWriteOUT <= 1'd0;
    MemWriteOUT <= 1'd0;
    isjalOUT <= 1'd0;
    ALUOPOUT <= 5'd0;
    RegSelectedOUT <= 5'd0;
    RD1OUT <= 32'd0;
    RD2OUT <= 32'd0;
    ext32OUT <= 32'd0;
    PCplus8OUT <= 32'd0;
    ETnewOUT <= 4'd0;
    instrOUT <= 32'd0;
    Ers <= 5'd0;
    Ert <= 5'd0;
    PCOUT <= 32'h00003000;
    EmemMark <= 6'd0;
    EaluSel <= 0;
end

always @(posedge clk) begin
    if (reset==1||Ereset==1) begin
        ALUSrcOUT <= 1'd0;
        MemtoRegOUT <= 1'd0;
        RegWriteOUT <= 1'd0;
        MemWriteOUT <= 1'd0;
        isjalOUT <= 1'd0;
        ALUOPOUT <= 5'd0;
        RegSelectedOUT <= 5'd0;
        RD1OUT <= 32'd0;
        RD2OUT <= 32'd0;
        ext32OUT <= 32'd0;
        PCplus8OUT <= 32'd0;
        ETnewOUT <= 4'd0;
        instrOUT <= 32'd0;
        Ers <= 5'd0;
        Ert <= 5'd0;
        PCOUT <= 32'h00003000;
        EmemMark <= 6'd0;
        EaluSel <= 0;
    end
    else begin
        RegSelectedOUT <= RegSelectedIN;
        RD1OUT <= RD1IN;
        RD2OUT <= RD2IN;
        ext32OUT <= ext32IN;
        PCplus8OUT <= PCplus8IN;
        ALUSrcOUT <= ALUSrcIN;
        MemtoRegOUT <= MemtoRegIN;
        RegWriteOUT <= RegWriteIN;
        MemWriteOUT <= MemWriteIN;
        isjalOUT <= isjalIN;
        ALUOPOUT <= ALUOPIN;
        ETnewOUT <= ETnewIN;
        instrOUT <= instrIN;
        PCOUT <= PCIN;
        Ers <= Drs;
        Ert <= Drt;
        EaluSel <= aluSel;
        EmemMark <= DmemMark;
    end
end

endmodule
