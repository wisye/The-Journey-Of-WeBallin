int hatsune_miku_no_gekishou(int x, int y){
    int min = 1 << 31;
    int max = ~min;
    int sum = x + y;
    int negx = x >> 31;
    int negsum = sum >> 31;
    int overflow = (~(x ^ y) & (x ^ sum)) >> 31;
    return (~overflow & sum) | (~negx & (overflow & max)) | (negx & (overflow & min));
}
