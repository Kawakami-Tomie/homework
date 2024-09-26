module wys_1780_3(codeout,clk,en,Q);
	input clk,en;
	output [2: 0] Q; //计数器输出信号
	output [5: 0] codeout; //输出信号
	wys_1780_3_1 a(clk,en,Q);
	wys_1780_3_2 b(codeout, Q);
endmodule