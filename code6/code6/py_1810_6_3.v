module py_1810_6_3(SEL,data);//数据选择器
input [1:0] SEL;
output reg [3:0] data;
always @(SEL)
begin
   case(SEL)    
	      2'b00:data<=4'b0111;
			2'b01:data<=4'b1000;
			2'b10:data<=4'b0000;
			//default:data<=4'bx;
   endcase
end
endmodule
