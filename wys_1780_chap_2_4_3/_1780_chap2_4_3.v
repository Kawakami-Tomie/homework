module _1780_chap2_4_3 (A,B,SEL,L);
input A,B,SEL;
output L;
assign L = SEL ? B : A;
endmodule