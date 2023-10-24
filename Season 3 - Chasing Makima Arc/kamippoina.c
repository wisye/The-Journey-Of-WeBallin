int kamippoina(int n){
    // int x = 1 << (n + 1);
    // int y = 1;
    // int borr = ~y;
    // x = x + borr;
    // x = x + 1;
    // return x;

    // int x = 1 << (n + 1);
    // return x + ~0;

    return  (2 << n) + ~0;
}