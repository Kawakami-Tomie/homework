module wys_1780_chap_6_5(data,SEG);
	input [3:0] data;
	output reg [6:0] SEG;
	always @(data)
	begin
		case (data)
			4'd0: SEG <= 7'b1111110;
			4'd1: SEG <= 7'b0110000;
			4'd2: SEG <= 7'b1101101;
			4'd3: SEG <= 7'b1111001;
			4'd4: SEG <= 7'b0110011;
			4'd5: SEG <= 7'b1011011;
			4'd6: SEG <= 7'b1011111;
			4'd7: SEG <= 7'b1110000;
			4'd8: SEG <= 7'b1111111;
			4'd9: SEG <= 7'b1111011; 
			default: SEG <= 7'bx;
		endcase
	end
endmodule
