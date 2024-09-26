module wys_1780_6_4(din,dout);//数码管译码器

    input[3:0]din;
    output reg[6:0]dout;

    always@(din)
    begin
      case(din)
      4'd0:dout <= 7'b0111111;
      4'd1:dout <= 7'b0000110;
      4'd2:dout <= 7'b1011011;
      4'd3:dout <= 7'b1001111;
      4'd4:dout <= 7'b1100110;
      4'd5:dout <= 7'b1101101;
      4'd6:dout <= 7'b1111101;
      4'd7:dout <= 7'b0000111;
        4'd8:dout <= 7'b1111111;      
      4'd9:dout <= 7'b1101111;      
      default: dout <= 7'd0;
      endcase
    end 
  
endmodule
