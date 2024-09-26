module wys_1780_chap_6_6(SEL,DIG);
	input [1:0] SEL;
	output reg [3:1] DIG;
	always @(SEL)
	begin
	 case(SEL)
	  2'b00: DIG <= 3'b001;
	  2'b01: DIG <= 3'b010;
	  2'b10: DIG <= 3'b100;
	  default: DIG <= 3'bx;
	 endcase
	end 
endmodule
