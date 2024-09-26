module bg (P_out, Q, clk, en);
	input clk, en;
	output [2:0] P_out;
	output [2:0] Q;
	
	bg1 counter (Q, clk, en);    //八进制计数器
	bg2 decoder ( P_out, Q);    //译码器
	
endmodule