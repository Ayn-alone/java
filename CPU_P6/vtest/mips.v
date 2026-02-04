`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:29:00 11/10/2023 
// Design Name: 
// Module Name:    mips 
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
module mips(
    input clk,
    input reset,
    input [31:0] i_inst_rdata,
    input [31:0] m_data_rdata,
    output [31:0] i_inst_addr,
    output [31:0] m_data_addr,
    output [31:0] m_data_wdata,
    output [3 :0] m_data_byteen,
    output [31:0] m_inst_addr,
    output w_grf_we,
    output [4:0] w_grf_addr,
    output [31:0] w_grf_wdata,
    output [31:0] w_inst_addr
    );
wire [31:0] PCplus4,jal32,beq32,newPC,currentAddr,instr,Dinstr,DPCplus4,DPCplus8,EPCplus8,imm32,datatobeWritten;
wire [31:0] DRD1,DRD2,ERD1,ERD2,beqrest,index32,DTrueRD1,DTrueRD2,ETrueRD1,ETrueRD2,Eimm32,ALUSource,EALUdata,MPCplus8;
wire [31:0] WPCplus8,MRD2,MALUresult,Einstr,Minstr,MemData,WRD,WALUresult,DPC,EPC,MPC,WPC,mdata,aluResult,mdALUresult;
wire [25:0] index;
wire [15:0] imm;
wire [5:0] opcode,funct,DmemMark,EmemMark,MmemMark;
wire [4:0] Drs,Drt,Drd,ALUop,RegSelected,WRegSelected,ERegSelected,MRegSelected;
wire [4:0] Ers,Ert,EALUop;
wire [3:0] Tuse,Tnew,DTuse,DTnew,preETnew,ETnew,preMTnew,MTnew,preWTnew,WTnew,DRD1Judge,ERD1Judge,DRD2Judge,ERD2Judge;
wire jumpJudege,isjal,isbeq,isjr,PCenable,Denable,extop,RegDst,ALUSrc,MemtoReg,RegWrite,MemWrite;
wire EregWrite,MregWrite,WregWrite,Misjal,EALUSrc,MMemtoReg,MMemwrite,Eisjal,EMemtoReg,EMemwrite,aluSel,EaluSel,start,busy;
wire WMemtoReg,Wisjal,Ereset,equal;

/*
assign memMark = (opcode==sbop) ? 1
                :(opcode==shop) ? 2
                :(opcode==swop) ? 3
                :(opcode==lbop) ? 4
                :(opcode==lhop) ? 5
                :(opcode==lwop) ? 6
                :0;
*/
assign i_inst_addr = currentAddr;
assign m_data_addr = MALUresult;
assign m_data_wdata = (MmemMark==1&&m_data_byteen==4'b0001) ? {{24{1'b0}},MRD2[7:0]}
                    : (MmemMark==1&&m_data_byteen==4'b0010) ? {{16{1'b0}},MRD2[7:0],{8{1'B0}}}
                    : (MmemMark==1&&m_data_byteen==4'b0100) ? {{8{1'B0}},MRD2[7:0],{{16{1'b0}}}}
                    : (MmemMark==1&&m_data_byteen==4'b1000) ? {MRD2[7:0],{24{1'b0}}}
                    : (MmemMark==2&&m_data_byteen==4'b0011) ? {{16{1'b0}},MRD2[15:0]} 
                    : (MmemMark==2&&m_data_byteen==4'b1100) ? {MRD2[15:0],{16{1'b0}}}
                    : MRD2;
assign m_inst_addr = MPC;
assign w_grf_we = WregWrite;
assign w_grf_addr = WRegSelected;
assign w_grf_wdata = datatobeWritten;
assign w_inst_addr = WPC;

/*
module PCsel(
    input [31:0] jal32,
    input [31:0] jr32,
    input [31:0] beq32,
    input [31:0] PCplus4,
    input jumpJudge,
    input isjal,
    input isjr,
    input isbeq,
    output [31:0] newPC
    );
*/
PCsel pcsel(jal32,DTrueRD1,beq32,PCplus4,jumpJudege,isjal,isjr,isbeq,newPC);

/*
module PC(
    input reset,
    input enable,
    input clk,
    input [31:0] newAddress,
    output reg [31:0] currentAddress
    );
*/
PC pc(reset,PCenable,clk,newPC,currentAddr);

/*
module CMP(
    input isbeq,
    input isjal,
    input isjr,
    input equal,
    output jumpJudge,
    input [31:0] RD1,
    input [31:0] RD2
    );
*/
CMP cmp(isbeq,isjal,isjr,equal,jumpJudege,DTrueRD1,DTrueRD2);
/*
module TimeTranslator(
    input [31:0] instr,
    output [3:0] Tuse,
    output [3:0] Tnew
    );
*/
TimeTranslator tt(i_inst_rdata,Tuse,Tnew);

/*
module ADD4(
    input [31:0] Original,
    output [31:0] Originalplus4
    );
*/
ADD4 add4a(currentAddr,PCplus4);
ADD4 add4b(DPCplus4,DPCplus8);

/*
module RegisterD(
    input clk, 
    input reset,
    input enable,
    input [31:0] instrIN,
    input [31:0] pcIN,
    input [31:0] PCplus4IN, 
    input [3:0] TuseIN,
    input [3:0] DTnewIN,
    input [5:0] DmemMark,
    output reg [5:0] EmemMark,
    output reg [31:0] pcOUT,
    output reg [3:0] DTnewOUT,
    output reg [3:0] TuseOUT,
    output reg [31:0] instrOUT,
    output reg [31:0] PCplus4OUT
    );
*/
RegisterD regD(clk,reset,Denable,i_inst_rdata,currentAddr,PCplus4,Tuse,Tnew,DPC,DTnew,DTuse,Dinstr,DPCplus4);

/*
module Splitter(
    input [31:0] instr,
    output [5:0] opcode,
    output [4:0] rs,
    output [4:0] rt,
    output [4:0] rd,
    output [5:0] funct,
    output [25:0] index,
    output [15:0] imm
    );
*/
Splitter splitter(Dinstr,opcode,Drs,Drt,Drd,funct,index,imm);

/*
module EXT16(
    input [15:0] imm,
    input extop,
    output [31:0] imm32
    );
*/
EXT16 ext16(imm,extop,imm32);

/*
module Controller(
    input [5:0] opcode,
    input [5:0] funct,
    output equal,
    output RegDst,
    output ALUSrc,
    output MemtoReg,
    output RegWrite,
    output MemWrite,
    output Ext_Op,
    output isjal,
    output isjr,
    output isbeq,
    output aluSel,//0 for alu,1 for mdu
    output [4:0] ALUOP,
    output [5:0] memMark
    );
*/
D_control controller(opcode,funct,equal,RegDst,ALUSrc,MemtoReg,RegWrite,MemWrite,extop,isjal,isjr,isbeq,aluSel,ALUop,DmemMark);

/*
module RegSel(
    input [4:0] rt,
    input [4:0] rd,
    input aluSel,
    input isjal,
    input RegDst,
    input jumpjudge,
    output [4:0] RegSelected
    );
*/
RegSel regsel(Drt,Drd,aluSel,isjal,RegDst,jumpJudege,RegSelected);

/*
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
*/
GRF grf(Drs,Drt,WPC,reset,clk,WregWrite,WRegSelected,datatobeWritten,Dinstr,DRD1,DRD2);

/*
module ShiftLeft2(
    input [31:0] ext32,
    output [31:0] beqExpected
    );
*/
ShiftLeft2 sla(imm32,beqrest);
ShiftLeft2 slb(index32,jal32);

/*
module ADDER(
    input [31:0] PCplus4,
    input [31:0] addressRest,
    output [31:0] expectedAddress
    );
*/
ADDER add(DPCplus4,beqrest,beq32);

/*
module EXT26(
    input [25:0] index,
    input [31:0] PC,
    output [31:0] index32
    );
*/
EXT26 ext26(index,DPC,index32);

/*
module timeSwitcher(
    input [3:0] originalT,
    output [3:0] nowT
    );

*/
timeSwitcher tS1(DTnew,preETnew);
timeSwitcher tS2(ETnew,preMTnew);
timeSwitcher tS3(MTnew,preWTnew);

/*
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
*/
RegisterE regE(clk,reset,Ereset,Drs,Drt,RegSelected,DTrueRD1,DTrueRD2,imm32,DPCplus8,ALUSrc,MemtoReg,RegWrite,MemWrite,isjal,ALUop,preETnew,Dinstr,DPC,DmemMark,aluSel,EaluSel,EmemMark,EPC,Ers,Ert,Einstr,ETnew,EALUSrc,EMemtoReg,EregWrite,EMemwrite,Eisjal,EALUop,EPCplus8,Eimm32,ERegSelected,ERD1,ERD2);

/*
module ALUSel(
    input ALUSrc,
    input [31:0] RD2,
    input [31:0] ext32,
    output [31:0] alusource
    );
*/
ALUSel aluselection(EALUSrc,ETrueRD2,Eimm32,ALUSource);

/*
module ALU(
    input [31:0] read1,
    input [31:0] read2,
    input [4:0] aluop,
    output [31:0] aluData
    );
*/
ALU alu(ETrueRD1,ALUSource,EALUop,aluResult);

/*
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
*/
RegisterM regM(clk,reset,ERegSelected,EALUdata,ETrueRD2,EPCplus8,EMemtoReg,EregWrite,EMemwrite,Eisjal,preMTnew,Einstr,EPC,EmemMark,MmemMark,MPC,Minstr,MTnew,MMemtoReg,MregWrite,MMemwrite,Misjal,MPCplus8,MRD2,MRegSelected,MALUresult);


/*
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
*/
RegisterW regW(clk,reset,MRegSelected,MALUresult,mdata,MPCplus8,MMemtoReg,MregWrite,Misjal,preWTnew,MPC,WPC,WTnew,WMemtoReg,WregWrite,Wisjal,WPCplus8,WRD,WRegSelected,WALUresult);

/*
module RegDataSel(
    input [31:0] MemData,
    input [31:0] AluData,
    input [31:0] PCplus8,
    input MemToReg,
    input isjal,
    output [31:0] RegData
    );
*/
RegDataSel regdatasel(WRD,WALUresult,WPCplus8,WMemtoReg,Wisjal,datatobeWritten);
/*
module BE(
    input [5:0] MmemMark,
    input [31:0] address,
    output [3:0] m_data_byteen
    );
*/
BE be(MmemMark,MALUresult,m_data_byteen);
/*
module Mext(
    input [31:0] m_data_rdata,
    input [5:0] MmemMark,
    input [31:0] address,
    output [31:0] mdata
    );
*/
Mext mext(m_data_rdata,MmemMark,MALUresult,mdata);
/*
module mALU(
    input [4:0] aluop,
    input [31:0] read1,
    input [31:0] read2,
    input clk,
    input reset,
    input aluSel,
    output reg start,
    output reg busy,
    output [31:0] result
    );
*/
mALU malu(EALUop,ETrueRD1,ETrueRD2,clk,reset,EaluSel,start,busy,mdALUresult);
/*
module ALUResultSel(
    input [31:0] aluResult,
    input [31:0] maluResult,
    input aluSel,
    output [31:0] trueAluResult
    );
*/
ALUResultSel alursel(aluResult,mdALUresult,EaluSel,EALUdata);
/*
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
*/
HazardControl hzc(Drs,Drt,Ers,Ert,DTuse,ETnew,MTnew,WTnew,ERegSelected,MRegSelected,WRegSelected,isjal,EregWrite,MregWrite,WregWrite,EMemtoReg,MMemtoReg,start,busy,aluSel,PCenable,Denable,Ereset,DRD1Judge,ERD1Judge,DRD2Judge,ERD2Judge);

/*
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
*/
DTrueRD1 dtrd1(DRD1,MALUresult,datatobeWritten,Eisjal,Misjal,Wisjal,EPCplus8,MPCplus8,DRD1Judge,DTrueRD1);

/*
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
*/
DTrueRD2 dtrd2(DRD2,MALUresult,datatobeWritten,Eisjal,Misjal,Wisjal,EPCplus8,MPCplus8,DRD2Judge,DTrueRD2);

/*
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
*/
ETrueRD1 etrd1(Misjal,Wisjal,ERD1,MALUresult,datatobeWritten,ERD1Judge,MPCplus8,ETrueRD1);

/*
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
*/
ETrueRD2 etrd2(Misjal,Wisjal,ERD2,MALUresult,datatobeWritten,ERD2Judge,MPCplus8,ETrueRD2);

endmodule