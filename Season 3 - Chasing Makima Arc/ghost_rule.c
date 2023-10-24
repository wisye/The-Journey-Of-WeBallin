int ghost_rule(int n){
    // int x = n;
    // int var1 = ((n+1 >> 31) & 1);
    // int var2 = ((~n)+1 >> 31) + 1;

    // x = x + ~0;
    // int var = (n & x) + var1 + var2; // n & (n-1)
    // // 10000000
    // // 01111111

    // var = ((~var + 1) >> 31) + (var >> 31) + 1;

    int x = n + ~0;
    int var = ~(n & x) + 2;
    int iszero = ((~x + 1) & x >> 31) & 1;
    return (var) & (~(var >> 31)) & (~(n >> 31)) & ~iszero;
}