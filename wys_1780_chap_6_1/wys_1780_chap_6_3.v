module wys_1780_chap_6_3(clk_1kHz,SEL);
	input clk_1kHz;
	output reg [1:0] SEL = 2'd0;
	reg [1:0] counter;
	initial
	begin 
		counter = 2'b00;
		SEL = 2'b00;
	end
	always @(posedge clk_1kHz)
	begin 
		if(counter == 2'b10)
		begin 
			if(counter ==2'b00)
			begin 
			 counter <= 2'b00;
			 SEL <= 2'b00;
			end 
			else 
			begin
				counter <= counter +1;
			end 
			SEL <= counter;
		end
	end
endmodule
