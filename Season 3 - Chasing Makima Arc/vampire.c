int vampire(int x, int y){
    int notx = ~x;
    int noty = ~y;
    int var1 = x & noty;
    int var2 = y & notx;
    int var3 = var1 | var2;
    var3 = ~var3;
    return var3;
}