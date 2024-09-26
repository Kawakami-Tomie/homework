`timescale 1ns/1ns
module T_sdsheji;
reg one;
reg half;
reg reset;
reg clk;
wire ydrink;
wire ymoney;
wire [7:0]seg;
wire [7:0]out;

sdsheji test1(
.one(one),
.half(half),
.reset(reset),
.clk(clk),
.ydrink(ydrink),
.ymoney(ymoney),
.seg(seg),
.out(out)
);

initial begin
reset = 0;
half = 0;
one = 0;
clk = 0;
#100
reset = 1;
//连续投入0.5元
#200
half = 1;
#200
half = 0;
#200
half = 1;
#200
half = 0;
#200
half = 1;
#200
half = 0;
#20
reset = 0;
#20
reset = 1;
//连续投入一元
#200
one = 1;
#200
one = 0;
#200
one = 1;
#200
one = 0;
#20
reset = 0;
#20
reset = 1;
//先投1元，再投0.5元
#200
one =1;
#200
one = 0;
#200
half = 1;
#200
half = 0;
#20
reset = 0;
#20
reset = 1;
//先投0.5元，再投1元
#200
half =1;
#200
half= 0;
#200
one = 1;
#200
one = 0;
#20
reset = 0;
#20
reset = 1;

end


always #1 clk = ~clk;


endmodule