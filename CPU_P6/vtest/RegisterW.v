`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:25:47 11/08/2023 
// Design Name: 
// Module Name:    RegisterW 
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
module RegisterW(
    input clk,
    input reset,
    input [4:0] RegSelectedIN,
    input [31:0] aluResultIN,
    input [31:0] RDIN,
    input [31:0] PCplus8IN,
    input MemtoRegIN,
    input RegWriteIN,
    input isjalIN,
    input [3:0] WTnewIN,
    input [31:0] PCIN,
    output reg [31:0] PCOUT,
    output reg [3:0] WTnewOUT,
    output reg MemtoRegOUT,
    output reg RegWriteOUT,
    output reg isjalOUT,
    output reg [31:0] PCplus8OUT,
    output reg [31:0] RDOUT,
    output reg [4:0] RegSelectedOUT,
    output reg [31:0] aluResultOUT
    );

initial begin
    MemtoRegOUT <= 1'd0;
    RegWriteOUT <= 1'd0;
    isjalOUT <= 1'd0;
    RegSelectedOUT <= 5'd0;
    aluResultOUT <= 32'd0;
    RDOUT <= 32'd0;
    PCplus8OUT <= 32'd0;
    WTnewOUT <= 4'd0;
    PCOUT <= 32'h00003000;
end

always @(posedge clk) begin
    if (reset===1) begin
        MemtoRegOUT <= 1'd0;
        RegWriteOUT <= 1'd0;
        isjalOUT <= 1'd0;
        RegSelectedOUT <= 5'd0;
        aluResultOUT <= 32'd0;
        RDOUT <= 32'd0;
        PCplus8OUT <= 32'd0;
        WTnewOUT <= 4'd0;
        PCOUT <= 32'd0;
    end
    else begin
        RegSelectedOUT <= RegSelectedIN;
        aluResultOUT <= aluResultIN;
        RDOUT <= RDIN;
        PCplus8OUT <= PCplus8IN;
        MemtoRegOUT <= MemtoRegIN;
        RegWriteOUT <= RegWriteIN;
        isjalOUT <= isjalIN;
        WTnewOUT <=WTnewIN;
        PCOUT <= PCIN;
    end
end

endmodule
