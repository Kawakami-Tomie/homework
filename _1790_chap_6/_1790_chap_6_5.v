module _1790_chap_6_5(SEL,DIG);//2-3线译码器
input [1:0] SEL;
output reg [7:0] DIG;
always @(SEL)
begin
  case (SEL)//控制亮起的数码管是哪个
     2'b00:DIG<=8'b00000001;
	  2'b01:DIG<=8'b00000010;
	  2'b10:DIG<=8'b00000100;
	  default:DIG<=3'bx;
  endcase
end
endmodule 