//ModelSim仿真代码
`timescale 1ns/1ns       //时间单位和时间精度都为1ns
 module CW_2301_9_test();
 
	reg clk;                  //时钟信号输入
	reg en;                   //使能信号
	wire [2:0] Q;             //八进制计数器输出信号
	wire [2:0] P_out;         //阴阳信号发生器输出信号
	
	CW_2301_9 YinYangF(P_out, Q, clk, en);    //实例化
	
	initial 
		begin
	      clk = 0;   //时钟信号初始化为0
			en = 1;    //使能信号初始化为1
		end
	
	always#500000000 clk = ~clk;     //将时钟信号频率设置为1Hz
	
endmodule
