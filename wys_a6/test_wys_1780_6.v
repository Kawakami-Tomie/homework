
`timescale 10ns/1ns//时间单位10ns，时间精度1ns
module wys_1780_6_vlg_tst();


reg       clk_in  ;
reg       reset_n ;
wire      [6:0]D  ;
wire      [2:0]seg;   
wire      [3:0]Y;
wire      clk_1k;
initial
    begin
        clk_in <= 1'b1;
        reset_n <= 1'b0;
        # 5 reset_n <= 1'b1;
    end

always #1   clk_in = ~clk_in;//时钟周期为20ns

wys_1780_6  test_6_init
                      (  .clk_in(clk_in) ,
                          .rst(reset_n),
                          .D(D),
                          .seg(seg),
                          .Y(Y),
                          .clk_1k(clk_1k)
							 );
                                
endmodule


