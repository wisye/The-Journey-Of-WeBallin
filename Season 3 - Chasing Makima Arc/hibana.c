int hibana(int a, int b, int c){
    int difab = ((a + (~b + 1)) >> 31);
    int var1 = (~difab & a) | (b & difab);
    int difabc = ((var1 + (~c + 1)) >> 31);
    int var = (~difabc & var1) | (c & difabc);
    return var;
} // 1000 0000 0000 0000
  // 1111 1111 1111 1111 