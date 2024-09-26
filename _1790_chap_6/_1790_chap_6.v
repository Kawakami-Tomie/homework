module _1790_chap_6(clk_in,clk_1khz,DIG,SEL,data,SEG);
input clk_in;//系统信号
output clk_1khz;
output [1:0] SEL;
output [3:0] data;//存储后三位学号
output [7:0] DIG;//位选信号
output [6:0] SEG;//段选，哪一个数码管显示 SEG0-3
_1790_chap_6_1 a(clk_in,clk_1khz);
_1790_chap_6_2 b(clk_1khz,SEL);//计数器
_1790_chap_6_3 c(SEL,data);
_1790_chap_6_4 d(data,SEG);
_1790_chap_6_5 e(SEL,DIG);

endmodule