int internet_overdose(int i){
    int var1 = 0xFF;
    int var2 = 0xF0;
    int var3 = 0x0F;
    int var4 = 0x0C;
    int var5 = 0xC3;
    int var6 = 0x22;
    int var7 = 0x99;

    i = (i & (var1 << 8)) << 8 | (i >> 8) & (var1 << 8) | i & (var1 << 24 | var1);
    i = (i & (var2 << 16 | var2)) << 4 | (i >> 4) & (var2 << 16 | var2) | i & (var2 << 24 | var3 << 16 | var2 << 8 | var3);
    i = (i & (var4 << 24 | var4 << 16 | var4 << 8 | var4)) << 2 | (i >> 2) & (var4 << 24 | var4 << 16 | var4 << 8 | var4) | i & (var5 << 24 | var5 << 16 | var5 << 8 | var5);
    i = (i & (var6 << 24 | var6 << 16 | var6 << 8 | var6)) << 1 | (i >> 1) & (var6 << 24 | var6 << 16 | var6 << 8 | var6) | i & (var7 << 24 | var7 << 16 | var7 << 8 | var7);

    return (i);
}