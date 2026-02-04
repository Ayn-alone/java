`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:29:19 12/03/2023 
// Design Name: 
// Module Name:    mALU 
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
module mALU(
    input [4:0] Multop,
    input [31:0] A,
    input [31:0] B,
    input clk,
    input reset,
    input aluSel,
    output start,
    output reg busy,
    output [31:0] out
    );
	 
reg [31:0] Hi,Lo,Hi_temp,Lo_temp;
reg [4:0] max,cnt;

always @(posedge clk)
begin
   if (reset == 1)
	begin
		Hi<=0;
      Lo<=0;
      Hi_temp<=0;
		Lo_temp<=0;
	end
   else  if(busy==0&&aluSel==1)
		 begin
		    case(Multop)
			   0:begin//mult
				     {Hi_temp,Lo_temp}<=$signed(A)*$signed(B);
					  max<=5;
             end				
				1:begin//multu
				     {Hi_temp,Lo_temp}<=$unsigned(A)*$unsigned(B);
					  max<=5;
             end	
				 
				2:begin//div
				     {Hi_temp,Lo_temp}<={$signed(A)%$signed(B),$signed(A)/$signed(B)};
					  max<=10;
             end		
				3:begin//divu
				     {Hi_temp,Lo_temp}<={$unsigned(A)%$unsigned(B),$unsigned(A)/$unsigned(B)};
					  max<=10;
             end					
				6:Hi<=A;//mthi
				7:Lo<=A;//mtlo
			 endcase
		 end
	else
	 begin//mult,div
		if(cnt==max-1) {Hi,Lo}<={Hi_temp,Lo_temp};
	   else {Hi,Lo}<={Hi,Lo};
	 end
		  
end


always @(posedge clk) begin
    if(reset) begin
        cnt <= 0; busy <= 0;
    end
    else if(start) begin
        busy <= 1'b1;
    end
    else if(~start && busy)begin
        if(cnt == max - 1) begin
            cnt <= 0; busy <= 0;
        end
        else cnt <= cnt + 1;
    end
end

assign start = ((Multop==0||Multop==1||Multop==2||Multop==3)&&reset==0&&aluSel==1);//mult,multu,div,divu             
assign out = (Multop==4)?Hi://mfhi
             (Multop==5)?Lo:0;//mflo

endmodule
