int sharuru(int x, int y){
    int var1 = x & 0x0F;
    int var2 = y & 0xF0;
    return var1 | var2;
}