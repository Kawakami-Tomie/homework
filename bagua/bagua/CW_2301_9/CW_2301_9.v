//逆时针阴阳信号发生器（顶层文件）
module CW_2301_9 (P_out, Q, clk, en);
	input clk, en;
	output [2:0] P_out;
	output [2:0] Q;
	
	CW_2301_9_1 counter (Q, clk, en);    //八进制计数器
	CW_2301_9_2 decoder ( P_out, Q);    //译码器
	
endmodule
