`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:50:35 11/03/2023 
// Design Name: 
// Module Name:    Controller 
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
`define Ori 6'b001101//我的宏定义只有第一个字母大写
`define Or 6'b100101//注意这个是funct
`define Add 6'b100000//注意这个是funct
`define Sub 6'b100010//注意这个是funct
`define Jr 6'b001000//注意这个是funct

`define And 6'b100100//注意这个是funct

`define Div 6'b011010//注意这个是funct
`define Divu 6'b011011//注意这个是funct
`define Mult 6'b011000//注意这个是funct
`define Multu 6'b011001//注意这个是funct
`define Mfhi 6'b010000//注意这个是funct
`define Mflo 6'b010010//注意这个是funct
`define Mthi 6'b010001//注意这个是funct
`define Mtlo 6'b010011//注意这个是funct

`define Slt 6'b101010//注意这个是funct
`define Sltu 6'b101011//注意这个是funct

`define Lw 6'b100011
`define Sw 6'b101011
`define Beq 6'b000100
`define Lui 6'b001111
`define R 6'b000000
`define Jal 6'b000011

`define Addi 6'b001000

`define Andi 6'b001100

`define Bne 6'b000101

`define Lb 6'b100000
`define Lh 6'b100001
`define Sb 6'b101000
`define Sh 6'b101001


module D_control(
    input [5:0] op,
    input [5:0] funct,
    output equal,
    output RegDst,
    output ALUSrc,
    output MemtoReg,
    output RegWrite,
    output MemWrite,
    output EXTop,
    output isjal,
    output isjr,
    output isbeq,
    output aluSel,//0 for alu,1 for mdu
    output [4:0] ALUOP,
    output [5:0] memMark
    );
    reg ori,Or,add,sub,lw,sw,beq,lui,R,jal,jr,nop,And,div,divu,mult,multu,mfhi,mflo,mthi,mtlo,slt,sltu,addi,andi,bne,lb,lh,sb,sh;
    initial begin
        ori = 1'b0;
        add = 1'b0;
        sub = 1'b0;
        lw = 0;
        sw = 0;
        beq = 0;
        lui = 0;
        R = 0;
        jal = 0;
        jr = 1'b0;
		  Or=0; And=0; div=0; divu=0; mult=0; multu=0; mfhi=0; mflo=0; mthi=0; mtlo=0; slt=0; sltu=0; addi=0; andi=0; bne=0; lb=0; lh=0; sb=0; sh=0;
    end
always @(*)begin
        ori = 0;
        add = 0;
        sub = 0;
        lw = 0;
        sw = 0;
        beq = 0;
        lui = 0;
        R = 0;
        jal = 0;
        jr = 0;
		  Or=0; And=0; div=0; divu=0; mult=0; multu=0; mfhi=0; mflo=0; mthi=0; mtlo=0; slt=0; sltu=0; addi=0; andi=0; bne=0; lb=0; lh=0; sb=0; sh=0;
    case(op)
        `Ori:ori =1;
        `Lw:lw = 1;
        `Sw: sw = 1;
        `Beq:beq = 1;
        `Lui:lui = 1;
        `Jal:jal = 1;
		  `R:R = 1;
		  `Addi:addi=1;
			`Andi:andi=1;
			`Bne:bne=1;
			`Lb:lb=1;
			`Lh:lh=1;
			`Sb:sb=1;
			`Sh:sh=1;
			
        default:;
    endcase

    case(funct)
        `Add:add =(R==1)?1'b1:1'b0;		  
        `Sub:sub = (R==1)?1'b1:1'b0;
        `Jr:jr = (R==1)?1'b1:1'b0;

		  `And:And = (R==1)?1'b1:1'b0;
		  `Or:Or=(R==1)?1'b1:1'b0;//这俩要大写
		  `Div:div = (R==1)?1'b1:1'b0;
		  `Divu:divu = (R==1)?1'b1:1'b0;
		  `Mult:mult = (R==1)?1'b1:1'b0;
		  `Multu:multu = (R==1)?1'b1:1'b0;
		  `Mfhi:mfhi = (R==1)?1'b1:1'b0;
		  `Mflo:mflo = (R==1)?1'b1:1'b0;
		  `Mthi:mthi = (R==1)?1'b1:1'b0;
		  `Mtlo:mtlo = (R==1)?1'b1:1'b0;
		  `Slt:slt = (R==1)?1'b1:1'b0;
		  `Sltu:sltu = (R==1)?1'b1:1'b0;
		  default:;
    endcase  
end

wire cal_R,cal_I,shift,shiftv,load,store,branch,J,md,mt,mf;
assign cal_R = add|sub|And|Or|slt|sltu;
assign cal_I=addi|andi|ori;
assign load = lw|lh|lb;
assign store = sw|sh|sb;
assign branch = beq|bne;
assign md = mult|multu|div|divu;
assign mt = mthi|mtlo;
assign mf = mfhi|mflo;


//jr,lui diffrent!
    assign equal = beq;
	 assign RegDst = add|sub|And|Or|slt|sltu|mfhi|mflo;
	 assign ALUSrc = lw|sw|ori|lui|addi|andi|lh|sh|lb|sb|mfhi|mflo;
	 assign MemtoReg = load;
	 assign RegWrite = cal_R|cal_I|load|jal|mf|lui;//ori|Or|add|addi|And|andi|sub|lw|lui|jal|slt|sltu|mfhi|mflo|lb|lh;//
	 assign MemWrite = store;
	 assign EXTop = sw|lw|beq|bne|lb|sb|lh|sh|addi;
	 assign isjal = jal;
	 assign isjr = jr;
	 assign isbeq = branch;//beq跳转
	 assign aluSel =   (md)  ? 1
						:   (mf)  ? 1
						:   (mt)  ? 1
						:0 ;
	 
    assign ALUOP =   (sub)       ? 1 //sub
						:  (And)       ? 2 //and
						:  (andi)      ? 2
						:  (Or)        ? 3
						:  (ori)       ? 3
						:  (lui)       ? 4
						:  (slt)       ? 5
						:  (sltu)      ? 6
						:  (beq|bne)   ? 1
						:   (mult==1)?0:
	                  (multu==1)?1:
						   (div==1)?2:
						   (divu==1)?3:						  
						   (mfhi==1)?4:
						   (mflo==1)?5:
						   (mthi==1)?6:
						   (mtlo==1)?7:
						0;   	 						
						  
	assign memMark =    (sb) ? 1
							 :(sh) ? 2
							 :(sw) ? 3
							 :(lb) ? 4
							 :(lh) ? 5
							 :(lw) ? 6
							 :0;		

endmodule