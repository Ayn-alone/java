`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:57:13 11/10/2023 
// Design Name: 
// Module Name:    HazardControl 
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
module HazardControl(
    input [4:0] Drs,
    input [4:0] Drt,
    input [4:0] Ers,
    input [4:0] Ert,
    input [3:0] Tuse,
    input [3:0] ETnew,
    input [3:0] MTnew,
    input [3:0] WTnew,
    input [4:0] Ereg,
    input [4:0] Mreg,
    input [4:0] Wreg,
    input Disjal,
    input ERegWrite,
    input MRegWrite,
    input WRegWrite, 
    input EMemtoReg,
    input MMemtoReg,
    input start,
    input busy,
    input aluSel,
    output PCEnable,
    output DregEnable,
    output EregReset,
    output [3:0] DRD1Judge,
    output [3:0] ERD1Judge,
    output [3:0] DRD2Judge,
    output [3:0] ERD2Judge
    );
//assign PCEnable = !(Tuse<ETnew||Tuse<MTnew||Tuse<WTnew);
//assign DregEnable = !(Tuse<ETnew||Tuse<MTnew||Tuse<WTnew);
//assign EregReset = (Tuse<ETnew||Tuse<MTnew||Tuse<WTnew);
assign PCEnable = !((((Tuse<ETnew&&(Drs==Ereg||Drt==Ereg)&&Ereg!=0)||(Tuse<MTnew&&(Drs==Mreg||Drt==Mreg)&&Mreg!=0)||(Tuse<WTnew&&(Drs==Wreg||Drt==Wreg)&&Wreg!=0))&&Disjal==0)||(busy==1&&aluSel==1)||(start==1&&aluSel==1));
assign DregEnable = !((((Tuse<ETnew&&(Drs==Ereg||Drt==Ereg)&&Ereg!=0)||(Tuse<MTnew&&(Drs==Mreg||Drt==Mreg)&&Mreg!=0)||(Tuse<WTnew&&(Drs==Wreg||Drt==Wreg)&&Wreg!=0))&&Disjal==0)||(busy==1&&aluSel==1)||(start==1&&aluSel==1));
assign EregReset = (((Tuse<ETnew&&(Drs==Ereg||Drt==Ereg)&&Ereg!=0)||(Tuse<MTnew&&(Drs==Mreg||Drt==Mreg)&&Mreg!=0)||(Tuse<WTnew&&(Drs==Wreg||Drt==Wreg)&&Wreg!=0))&&Disjal==0)||(busy==1&&aluSel==1)||(start==1&&aluSel==1);
assign DRD1Judge = (Drs==Ereg&&ETnew==0&&ERegWrite==1&&EMemtoReg==0&&Ereg!=0) ? 4'd1//转发给D级RD1PC+8的信号
                :  (Drs==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0&&Mreg!=0) ? 4'd2//转发给D级RD1ALUResult的信号
                :  (Drs==Wreg&&WTnew==0&&WRegWrite==1&&Wreg!=0              ) ? 4'd3//转发给D级RD2DataSelected的信号
                :                                                               4'd0;//不进行转发的信号
assign DRD2Judge = (Drt==Ereg&&ETnew==0&&ERegWrite==1&&EMemtoReg==0&&Ereg!=0) ? 4'd1//转发给D级RD2PC+8的信号
                :  (Drt==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0&&Mreg!=0) ? 4'd2//转发给D级RD2ALUResult的信号
                :  (Drt==Wreg&&WTnew==0&&WRegWrite==1&&Wreg!=0              ) ? 4'd3//转发给D级RD2DataSelected的信号
                :                                                      4'd0;//不进行转发的信号
assign ERD1Judge = (Ers==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0&&Mreg!=0) ? 4'd1//转发给E级RD1ALUResult的信号
                :  (Ers==Wreg&&WTnew==0&&WRegWrite==1&&Wreg!=0              ) ? 4'd2//转发给E级RD1DataSelected的信号
                :                                                      4'd0;//不进行转发的信号;
assign ERD2Judge = (Ert==Mreg&&MTnew==0&&MRegWrite==1&&MMemtoReg==0&&Mreg!=0) ? 4'd1//转发给E级RD2ALUResult的信号
                :  (Ert==Wreg&&WTnew==0&&WRegWrite==1&&Wreg!=0              ) ? 4'd2//转发给E级RD2DataSelected的信号
                :                                                               4'd0;//不进行转发的信号;
endmodule
