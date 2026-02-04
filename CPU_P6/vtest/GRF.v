`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:21:48 11/02/2023 
// Design Name: 
// Module Name:    GRF 
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
module GRF(
    input [4:0] rs,
    input [4:0] rt,
    input [31:0] pc,
    input reset,
    input clk,
    input regWrite,
    input [4:0] regtobewritten, 
    input [31:0] datatobewritten, 
    input [31:0] instr,
    output [31:0] read1,
    output [31:0] read2
    );
reg [31:0] registers[0:31];
integer i;
initial begin
    for (i = 0;i <= 31 ;i = i + 1) begin
        registers[i]<=0;
    end
end
always @(posedge clk) begin
    if (reset==1) begin
        for (i = 0;i <= 31;i = i + 1) begin
            registers[i]<=0;
        end
    end
    else if(reset!=1&&regWrite==1)begin
        for (i = 0;i <= 31;i = i + 1) begin
            if (i==regtobewritten && i!=0) begin
                registers[i]<=datatobewritten;
            end
            else begin
                registers[i]<=registers[i];
            end
        end
    end
    
    else begin
        for (i = 0;i <= 31;i = i + 1) begin
            registers[i]<=registers[i];
        end
    end
end

assign read1 = registers[rs];
assign read2 = registers[rt];

endmodule
