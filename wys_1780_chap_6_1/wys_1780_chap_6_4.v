module wys_1780_chap_6_4(SEL,data);
	input [1:0] SEL;
	output reg [3:0] data;
	always @(SEL)
	begin 
		case (SEL)
			2'b00: data <= 4'b0001;
			2'b01: data <= 4'b0111;
			2'b10: data <= 4'b1000;
		endcase
	end
endmodule