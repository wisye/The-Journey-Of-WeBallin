int aidoru_shinetai(int a){
    int bit4 = a & 8;
    int bit1 = a & 1;
    bit4 = bit4 >> 3;
    bit1 = bit1 << 3;
    a = a & ~9;
    a = a | bit4 | bit1;
    return a;
}