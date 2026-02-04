`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:32:26 11/10/2023 
// Design Name: 
// Module Name:    TimeTranslator 
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
module TimeTranslator(
    input [31:0] instr,
    output [3:0] Tuse,
    output [3:0] Tnew
    );

parameter addop = 6'b000000;
parameter addiop= 6'b001000;
parameter subop = 6'b000000;
parameter andop = 6'b000000;
parameter andiop= 6'b001100;
parameter orop  = 6'b000000;
parameter oriop = 6'b001101;
parameter luiop = 6'b001111;
parameter sltop = 6'b000000;
parameter sltuop= 6'b000000;

parameter lbop  = 6'b100000;
parameter lhop  = 6'b100001;
parameter lwop  = 6'b100011;
parameter sbop  = 6'b101000;
parameter shop  = 6'b101001;
parameter swop  = 6'b101011;

parameter multop= 6'b000000;

parameter beqop = 6'b000100;
parameter bneop = 6'b000101;
parameter jalop = 6'b000011;
parameter jrop  = 6'b000000;


parameter addfun  = 6'b100000;
parameter subfun  = 6'b100010;
parameter andfun  = 6'b100100;
parameter orfun   = 6'b100101;
parameter sltfun  = 6'b101010;
parameter sltufun = 6'b101011;
parameter multfun = 6'b011000;
parameter multufun= 6'b011001;
parameter divfun  = 6'b011010;
parameter divufun = 6'b011011;
parameter mfhifun = 6'b010000;
parameter mflofun = 6'b010010;
parameter mthifun = 6'b010001;
parameter mtlofun = 6'b010011;
parameter jrfun   = 6'b001000;

wire [5:0] opcode;
wire [5:0] funct;
assign opcode = instr[31:26];
assign funct = instr[5:0];
assign Tuse =  (opcode==jrop&&funct==jrfun) ? 0
            :  (opcode==jalop) ? 0
            :  (opcode==beqop) ? 0
            :  (opcode==bneop) ? 0
            :1;
assign Tnew =  (opcode==lbop) ? 3
            :  (opcode==lhop) ? 3
            :  (opcode==lwop) ? 3
            :  (opcode==sbop) ? 0
            :  (opcode==shop) ? 0
            :  (opcode==swop) ? 0
            :  (opcode==beqop)? 0
            :  (opcode==bneop)? 0
            :  (opcode==jalop)? 0
            :  (opcode==jrop&&funct==jrfun) ? 0
            :2;  
endmodule