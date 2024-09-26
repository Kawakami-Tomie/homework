module wys_1780_6_3 (input [3:0]data0,
                     input [3:0]data1,
                     input [3:0]data2,
                     input [1:0]sel,
                     output reg [3:0]Y);//数据选择器
                     
    always @ (*)
    case (sel)
        2'd0 : Y <= data0;
        2'd1 : Y <= data1;
        2'd2 : Y <= data2;
    endcase 
    
endmodule
