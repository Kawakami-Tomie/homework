module wys_1780_6(  input clk_in ,input rst,output [6:0]D,output [7:0]seg,output wire [3:0]Y ,output wire clk_1k);

    wire [1:0]co; //计数器
    wire [3:0]data2 = 4'd0;
    wire [3:0]data1 = 4'd8;
    wire [3:0]data0 = 4'd7; //学号780
   
    wys_1780_6_1 u1 (clk_in, rst, clk_1k);//1kHz时钟
    wys_1780_6_2 u2 (clk_1k, rst, co);
    wys_1780_6_3 u3 (data0, data1, data2, co, Y);
    wys_1780_6_4 u4(Y, D);
    wys_1780_6_5 u5 (co, seg);
    
endmodule
