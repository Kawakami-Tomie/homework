module wys_1780_chap_6_2(clk_in,clk_1kHz); // 将50MH2转换为1kHz的分频器
	input clk_in;
	output reg clk_1kHz;
	reg [14:0] counter;
	initial
	begin 
	 counter = 15'b000000000000000;
	 clk_1kHz = 1'b0;
	end
	always @(posedge clk_in)
	begin
		if (counter == 15'b110000110100111)
		begin
			counter <= 15'b00000000000000;
			clk_1kHz<= ~clk_1kHz;
		end
		else 
			counter <= counter+1;
	end 
endmodule
		
	