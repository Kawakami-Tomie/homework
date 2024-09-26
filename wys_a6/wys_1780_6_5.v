module wys_1780_6_5 (input [1:0]co,
                        output reg [2:0]seg);//23译码器
    always @ (*)
    case (co)
        2'd0 : seg <= 3'b001;
        2'd1 : seg <= 3'b010;
        2'd2 : seg <= 3'b100;
    endcase 
    
endmodule
