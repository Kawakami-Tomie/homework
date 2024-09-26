`timescale 1 ns/ 1 ns
module jmw_1763_8_tb();
reg clk;
reg f0;
reg p;
reg sta;                                              
wire f1;
wire f2;
                      
jmw_1763_8 i1 (
    .clk(clk),
    .f0(f0),
    .f1(f1),
    .f2(f2),
    .p(p),
    .sta(sta)
);
initial                                                
begin                                                 
clk = 0;
f0 = 0;
p = 0;
sta = 0;
#11000000 p = 1 ;
#10000000 sta = 1;
                                                       
end                                                    
always #20 clk = ~clk;
always                                                 
begin                                                 
      //繁殖季
    f0 = 1;    #500000;
    f0 = 0;    #500000;
    
    f0 = 1;    #400000;
    f0 = 0;    #600000;

    f0 = 1;    #300000;
    f0 = 0;    #700000;
    
    f0 = 1;    #300000;
    f0 = 0;    #700000;
    
    f0 = 1;    #300000;
    f0 = 0;    #700000;
    //年老时
    f0 = 1;    #200000;
    f0 = 0;    #800000;//20%
    
    f0 = 1;    #100000;
    f0 = 0;    #900000;//10%S
    
    f0 = 1;    #50000;
    f0 = 0;    #950000;//5%                            
end                                                    
endmodule
