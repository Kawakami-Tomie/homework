module wys_1780_1(din,dout,seg);
input [3:0] din;
output reg[7:0] dout;

output seg;
assign seg=1'b1;
always@(din)
begin 
   case(din)
	//                gfedcba
	4'b0000:dout<=8'b00111111;//0
	4'b0001:dout<=8'b00000110;//1
	4'b0010:dout<=8'b01011011;//2
	4'b0011:dout<=8'b01001111;//3
	4'b0100:dout<=8'b01100110;//4
	4'b0101:dout<=8'b01101101;//5
	4'b0110:dout<=8'b01111101;//6
	4'b0111:dout<=8'b00000111;//7
	4'b1000:dout<=8'b01111111;//8
	4'b1001:dout<=8'b01101111;//9
	default:dout<=8'd0;
	endcase
end
endmodule
