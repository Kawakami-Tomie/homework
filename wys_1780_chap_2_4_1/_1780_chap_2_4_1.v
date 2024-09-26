//Gate-level description of a 2-to-1-line multiplexer
module _1780_chap_2_4_1(A, B, SEL, L);
input A, B, SEL; //定义输入信号
output L; //定义输出信号
wire selnot, A1, B1 ; //定义内部节点信号数据类型
not U1(selnot, SEL);
and U2(A1, A, selnot);
and U3(B1, B, SEL);
or U4(L, A1, B1);
endmodule