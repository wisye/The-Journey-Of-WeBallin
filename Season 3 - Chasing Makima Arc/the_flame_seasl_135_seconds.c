int the_flame_seasl_135_seconds(int x){
    int var1, var2, var3, var4, var5, sign;

    x = ~x;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    x = ~x;

    var1 = 0x55 | (0x55 << 8);
    var1 = var1 | (var1 << 16);

    var2 = 0x33 | (0x33 << 8);
    var2 = var2 | (var2 << 16);

    var3 = 0x0F | (0x0F << 8);
    var3 = var3 | (var3 << 16);

    var4 = 0xFF | (0xFF << 16);

    var5 = 0xFF | (0xFF << 8);

    sign = x >> 31 & 1;
    x = x & ~(1 << 31);

    x = (x & var1) + ((x >> 1) & var1);
    x = (x & var2) + ((x >> 2) & var2);
    x = (x & var3) + ((x >> 4) & var3);
    x = (x & var4) + ((x >> 8) & var4);
    x = (x & var5) + ((x >> 16) & var5);

    x = x + sign;
    return x;
}