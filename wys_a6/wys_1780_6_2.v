module wys_1780_6_2 (input clk_in,input rst, output reg [1:0]co);//计数器

    always @ (posedge clk_in)
    begin
        if (!rst)
            co <= 2'd0;
        else if (co < 2'd2)
            co <= co + 1'b1;
        else
            co <= 2'd0;
    end
    
endmodule
