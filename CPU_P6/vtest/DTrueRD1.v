`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:48:27 11/10/2023 
// Design Name: 
// Module Name:    DTrueRD1 
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
module DTrueRD1(
    input [31:0] RD1,
    input [31:0] ALUResult,
    input [31:0] DataSelected,
    input Eisjal,
    input Misjal,
    input Wisjal, 
    input [31:0] EPCplus8,
    input [31:0] MPCplus8,
    input [3:0] DRD1Judge,
    output [31:0] trueRD1
    ); 
/*
assign DRD1Judge = (Drs==Ereg&&ETnew==0&&ERegWrite==1&&EMemtoReg==0) ? 4'd1//转发给D级RD1PC+8的信号
                :  (Drs==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0) ? 4'd2//转发给D级RD1ALUResult的信号
                :  (Drs==Wreg&&WTnew==0&&WRegWrite==1              ) ? 4'd3//转发给D级RD2DataSelected的信号
                :                                                      4'd0;//不进行转发的信号
*/
assign trueRD1 = (Eisjal==1&&DRD1Judge==4'd1) ? EPCplus8
                :(Misjal==0&&DRD1Judge==4'd2) ? ALUResult
                :(Misjal==1&&DRD1Judge==4'd2) ? MPCplus8
                :(DRD1Judge==4'd3) ? DataSelected
                : RD1;
endmodule
