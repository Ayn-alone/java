`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:55:19 11/10/2023 
// Design Name: 
// Module Name:    ETrueRD2 
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
module ETrueRD2(
    input Misjal,
    input Wisjal, 
    input [31:0] RD2, 
    input [31:0] ALUResult,
    input [31:0] DataSelected,
    input [3:0] ERD2Judge,
    input [31:0] MPCplus8,
    output [31:0] trueRD2
    );
/*
assign ERD2Judge = (Ert==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0) ? 4'd1//转发给E级RD2ALUResult的信号
                :  (Ert==Wreg&&WTnew==0&&WRegWrite==1              ) ? 4'd2//转发给E级RD2DataSelected的信号
                :                                                      4'd0;//不进行转发的信号;
*/
assign trueRD2 = (ERD2Judge==4'd1&&Misjal==0) ? ALUResult 
               : (ERD2Judge==4'd1&&Misjal==1) ? MPCplus8
               : (ERD2Judge==4'd2) ? DataSelected 
               : RD2;
endmodule
