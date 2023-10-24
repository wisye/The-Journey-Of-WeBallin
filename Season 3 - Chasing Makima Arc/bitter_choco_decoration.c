int bitter_choco_decoration(int x){
    int x0 = x << 4;
    int x1 = x << 2;
    int x2 = x << 1;
    x = x0 + x1 + x2 + x;
    return x;
}