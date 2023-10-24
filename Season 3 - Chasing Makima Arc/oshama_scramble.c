int oshama_scramble(unsigned uf){
    // unsigned sign = uf >> 31;
    // int e = (uf >> 23) & 0xFF;
    // int mantissa = (uf & 0x7FFFFF) | 0x800000;
    // int exp = e - 127;
    // int bin;

    // if(e == 0xFF){
    //     return 0x80000000u;
    // }
    // if(exp < 0){
    //     return 0;
    // }
    // else if(exp <= 23){
    //     bin = mantissa >> (23 - exp);
    // }
    // else if(exp <= 31){
    //     bin = mantissa << (exp - 23);
    // }
    // else{
    //     if(sign){
    //         return INT_MIN;
    //     }
    //     else{
    //         return INT_MAX;
    //     }
    // if (sign){
    //     bin = -bin;
    // }
    // return (bin);
// }

    return (*(int *)&uf & 0x7FFFFFFF) | (*(int *)&uf & 0x80000000) | ((*(int *)&uf & 0x7F800000) >> 1);
}