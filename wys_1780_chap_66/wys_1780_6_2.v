module wys_1780_6_1  //1000Hz
(
    input   wire            clk_in  ,
    input   wire            reset_n ,
    output  wire            clk_out 
);

parameter   CNT_CLK1 = (50000000/1000 - 1) ;
parameter   CNT_CLK1_HIGH = (CNT_CLK1+1)/2-1;

reg [19:0]  CNT0 ;

//CNT的计数逻辑
always@(posedge clk_in, negedge reset_n)
    begin
        if(!reset_n)
          begin
            CNT0 <= 20'd0;
          end
        else    if(CNT0 >= CNT_CLK1)
            CNT0 <= 20'd0;
        else
        begin          
            CNT0 <= CNT0 + 1'b1;
          end
    end

//clk_out的逻辑
assign clk_out =  (CNT0 <= CNT_CLK1_HIGH) ? 1'b1:1'b0;

endmodule
