module _1790_chap_6_2(clk_1khz,SEL);//计数器
input clk_1khz;
output reg [1:0] SEL=2'd0;
reg [1:0] counter;
initial
begin
   counter=2'b00;
	SEL=2'b00;
end
always @(posedge clk_1khz)
begin
 if(counter==2'b10)
      begin
		   counter<=2'b00;
			SEL<=2'b00;
		end
 else
    begin
	     counter<=counter+1;
	 end
	 SEL<=counter;
end
endmodule
 