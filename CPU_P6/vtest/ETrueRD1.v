`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:54:20 11/10/2023 
// Design Name: 
// Module Name:    ETrueRD1 
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
module ETrueRD1(
    input Misjal,
    input Wisjal, 
    input [31:0] RD1, 
    input [31:0] ALUResult,
    input [31:0] DataSelected,
    input [3:0] ERD1Judge,
    input [31:0] MPCplus8,
    output [31:0] trueRD1
    );
/*
assign ERD1Judge = (Ers==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0) ? 4'd1//转发给E级RD1ALUResult的信号
                :  (Ers==Wreg&&WTnew==0&&WRegWrite==1              ) ? 4'd2//转发给E级RD1DataSelected的信号
                :                                                      4'd0;//不进行转发的信号;
*/
assign trueRD1 = (ERD1Judge==4'd1&&Misjal==0) ? ALUResult 
               : (ERD1Judge==4'd1&&Misjal==1) ? MPCplus8
               : (ERD1Judge==4'd2) ? DataSelected 
               : RD1;
endmodule
