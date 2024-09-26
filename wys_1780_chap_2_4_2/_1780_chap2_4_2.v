module _1780_chap2_4_2 (A,B,SEL,L);
input A,B,SEL;
output L;
tri L;
bufif0 (L,A,SEL);
bufif1 (L,B,SEL);
endmodule