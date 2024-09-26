`timescale 10 ns/ 1 ns
module wys_1780_5_test();

reg clk_in;
reg sel;
wire [1:0] clk_out;
wys_1780_5 i1(
.clk_in(clk_in),
.clk_out(clk_out),
.sel(sel)
);
initial
begin
    sel=1'b0;
	 clk_in=1'b0;
	 #500000
	 sel=1'b1;
	 end
always
	 begin
	 #1
	 clk_in=~clk_in;
end
endmodule
