`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:13:20 12/02/2023 
// Design Name: 
// Module Name:    BE 
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
module BE(
    input [5:0] MmemMark,
    input [31:0] address,
    output [3:0] m_data_byteen
    );

wire [1:0] addr2;
/*
assign memMark = (opcode==sbop) ? 1
                :(opcode==shop) ? 2
                :(opcode==swop) ? 3
                :0;
*/
assign addr2 = address[1:0];
assign m_data_byteen = (MmemMark==1&&addr2==2'b00) ? 4'b0001
                    :  (MmemMark==1&&addr2==2'b01) ? 4'b0010
                    :  (MmemMark==1&&addr2==2'b10) ? 4'b0100
                    :  (MmemMark==1&&addr2==2'b11) ? 4'b1000
                    :  (MmemMark==2&&addr2[1]==0)  ? 4'b0011
                    :  (MmemMark==2&&addr2[1]==1)  ? 4'b1100
                    :  (MmemMark==3) ? 4'b1111
                    :0;

                    

endmodule
