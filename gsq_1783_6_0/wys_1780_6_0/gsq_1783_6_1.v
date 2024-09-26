module wys_1780_6_1(clk_in,clk_1khz);

input clk_in;
output reg clk_1khz;
reg [14:0] counter;
initial
begin
   counter=15'b000000000000000;
	clk_1khz=1'b0;
end
always@(posedge clk_in)
begin
   if(counter==15'b110000110100111)
	begin
	    counter<=15'b000000000000000;
		 clk_1khz<=~clk_1khz;
   end
	else
	   counter<=counter+1;
	end
endmodule
  