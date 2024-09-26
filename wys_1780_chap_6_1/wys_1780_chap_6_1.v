module wys_1780_chap_6_1(clk_in, clk_1kHz,DIG,SEL,data,SEG);//顶层模块
	input clk_in;
	output clk_1kHz;
	output [1:0] SEL;
	output [3:0] data;
	output [3:1] DIG;
	output [6:0] SEG;
	wys_1780_chap_6_2(c1k_in,c1k_1kHz);
	wys_1780_chap_6_3(clk_1kHz,SEL);
	wys_1780_chap_6_4(SEL,data);
	wys_1780_chap_6_5(data,SEG);
	wys_1780_chap_6_6(SEL,DIG);
endmodule
 