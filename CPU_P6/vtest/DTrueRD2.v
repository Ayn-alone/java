`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:53:13 11/10/2023 
// Design Name: 
// Module Name:    DTrueRD2 
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
module DTrueRD2(
    input [31:0] RD2, 
    input [31:0] ALUResult,
    input [31:0] DataSelected,
    input Eisjal,
    input Misjal,
    input Wisjal, 
    input [31:0] EPCplus8,
    input [31:0] MPCplus8,
    input [3:0] DRD2Judge,
    output [31:0] trueRD2
    );
/*
assign DRD2Judge = (Drt==Ereg&&ETnew==0&&ERegWrite==1&&EMemtoReg==0) ? 4'd1//转发给D级RD2PC+8的信号
                :  (Drt==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0) ? 4'd2//转发给D级RD2ALUResult的信号
                :  (Drt==Wreg&&WTnew==0&&WRegWrite==1              ) ? 4'd3//转发给D级RD2DataSelected的信号
                :                                                      4'd0;//不进行转发的信号
*/
assign trueRD2 = (Eisjal==1&&DRD2Judge==4'd1) ? EPCplus8
                :(Misjal==0&&DRD2Judge==4'd2) ? ALUResult
                :(Misjal==1&&DRD2Judge==4'd2) ? MPCplus8
                :(DRD2Judge==4'd3) ? DataSelected
                : RD2;
endmodule
