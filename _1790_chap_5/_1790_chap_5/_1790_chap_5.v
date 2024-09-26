//module _1790_chap_5(clk_in, sel ,clk_out);
//input clk_in;
//input sel;
//output reg[1:0] clk_out;
//
//reg [15:0] counter;					// 计数器，用于分频
//parameter num = 16'd50000/4 ;	//
//integer counter2;						// 将1790Hz频率再分频
//
//initial
//begin
//	counter = 0;
//	counter2 = 0;
//	clk_out = 0;
//end
//
//always@(posedge clk_in)
//begin
//	if(counter >= num - 1)
//	begin
//		counter <= 0;
//		clk_out[0] = ~clk_out[0];
//		counter2 = counter2 + 1'b1;
//	end
//	else
//	begin
//		counter <= counter + 1'b1;
//	end
//	
//	
//	
//	if(counter2 >= 4 && sel)
//	begin
//		clk_out[1] <= ~clk_out[1];
//		counter2 = 0;
//	end
//	else if(counter2 >= 2 && (!sel))
//	begin
//		clk_out[1] <= ~clk_out[1];
//		counter2 = 0;
//	end
//	
//	
//end
//endmodule

module _1790_chap_5(clk_in, sel, clk_out);  
input clk_in;  
input sel;  
output reg[1:0] clk_out;  
  
reg [15:0] counter; // 计数器，用于分频  
parameter num = 16'd50000 ; //  
parameter num_20 = num / 5; // 为了得到20%的占空比  
reg [15:0] counter2; // 使用reg类型以便在always块中保持状态  
  
always@(posedge clk_in)  
begin  
    if(counter >= num - 1)  
    begin  
        counter <= 0;  
        clk_out[0] <= ~clk_out[0]; // 使用非阻塞赋值  
        if(counter2 >= num_20 - 1 && sel) // 如果sel为高且counter2达到20%的阈值  
        begin  
            counter2 <= 0; // 重置counter2  
        end  
        else  
        begin  
            if(sel)  
                counter2 <= (counter2 + 1) % num; // 如果sel为高，继续计数直到num_20-1  
            else  
                counter2 <= 0; // 如果sel不为高，重置counter2  
        end  
    end  
    else  
    begin  
        counter <= counter + 1;  
        if(sel)  
            counter2 <= (counter2 + 1) % num; // 如果sel为高，继续计数  
        else  
            counter2 <= 0; // 如果sel不为高，重置counter2  
    end  
  
    // 设置clk_out[1]的值  
    if(sel && counter2 < num_20) // 如果sel为高且counter2在20%的范围内  
        clk_out[1] <= 1;  
    else  
        clk_out[1] <= 0;  
end  
  
initial  
begin  
    counter = 0;  
    counter2 = 0;  
    clk_out = 2'b00; // 初始化为0  
end  
  
endmodule

//
//module _1790_chap_5(clk_in, sel, clk_out);  
//input clk_in;  
//input sel;  
//output reg[1:0] clk_out;  
//  
//reg [15:0] counter;                  // 计数器，用于分频  
//parameter num = 16'd50000 / 4;       // 假设这是为了得到基础时钟的一半频率  
//integer counter2;                    // 用于控制clk_out[1]的翻转  
//  
//initial begin  
//    counter = 0;  
//    counter2 = 0;  
//    clk_out = 2'b00; // 初始化为0  
//end  
//  
//always @(posedge clk_in) begin  
//    if (counter >= num - 1) begin  
//        counter <= 0;  
//        clk_out[0] <= ~clk_out[0]; // 翻转clk_out[0]以产生基础时钟的一半频率  
//  
//        // 根据sel的值来设置counter2的阈值  
//        if (sel) begin  
//            // 对于20%占空比，我们在4个基础时钟周期中翻转1次clk_out[1]  
//            if (counter2 == 3) begin // 因为counter2从0开始计数，所以3表示第4个周期  
//                clk_out[1] <= ~clk_out[1];  
//            end  
//            counter2 <= (counter2 + 1) % 4; // 重置counter2并递增以计数下一个周期  
//        end else begin  
//            // 对于40%占空比，我们在4个基础时钟周期中翻转2次clk_out[1]  
//            if (counter2 == 1 || counter2 == 3) begin // 翻转两次  
//                clk_out[1] <= ~clk_out[1];  
//            end  
//            counter2 <= (counter2 + 1) % 4; // 重置counter2并递增以计数下一个周期  
//        end  
//    end else begin  
//        counter <= counter + 1;  
//    end  
//end  
//endmodule
