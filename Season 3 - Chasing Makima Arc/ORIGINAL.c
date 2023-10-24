#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int sharuru(int x, int y){
    int var1 = x & 0x0F;
    int var2 = y & 0xF0;
    return var1 | var2;
}

int vampire(int x, int y){
    int notx = ~x;
    int noty = ~y;
    int var1 = x & noty;
    int var2 = y & notx;
    int var3 = var1 | var2;
    var3 = ~var3;
    return var3;
}

int kamippoina(int n){
    // int x = 1 << (n + 1);
    // int y = 1;
    // int borr = ~y;
    // x = x + borr;
    // x = x + 1;
    // return x;

    return  (2 << n) + ~0;
}

int aidoru_shinetai(int a){
    int bit4 = a & 8;
    int bit1 = a & 1;
    bit4 = bit4 >> 3;
    bit1 = bit1 << 3;
    a = a & ~9;
    a = a | bit4 | bit1;
    return a;
}

int bitter_choco_decoration(int x){
    int x0 = x << 4;
    int x1 = x << 2;
    int x2 = x << 1;
    x = x0 + x1 + x2 + x;
    return x;
}

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

int hibana(int a, int b, int c){
    int difab = ((a + (~b + 1)) >> 31);
    int var1 = (~difab & a) | (b & difab);
    int difabc = ((var1 + (~c + 1)) >> 31);
    int var = (~difabc & var1) | (c & difabc);
    return var;
} // 1000 0000 0000 0000
  // 1111 1111 1111 1111 

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

int haikei_doppelganger(int x){
    int a = (x >> 24) & 0xFF;
    int b = (x >> 16) & 0xFF;
    int c = (x >> 8) & 0xFF;
    int d = x & 0xFF;

    int notA = ~a;
    int notB = ~b;
    int notC = ~c;
    int notD = ~d;
    int upper1 = ~0x5A;
    int upper2 = ~0x7A;

    int cekA1 = (0x41 + notA) & (a + upper1);
    int cekA2 = (0x61 + notA) & (a + upper2);
    int cekB1 = (0x41 + notB) & (b + upper1);
    int cekB2 = (0x61 + notB) & (b + upper2);
    int cekC1 = (0x41 + notC) & (c + upper1);
    int cekC2 = (0x61 + notC) & (c + upper2);
    int cekD1 = (0x41 + notD) & (d + upper1);
    int cekD2 = (0x61 + notD) & (d + upper2);

    int cek = (((cekA1 | cekA2) & (cekB1 | cekB2) & (cekC1 | cekC2) & (cekD1 | cekD2)) >> 31) & 1;
    return (cek);
}

int hatsune_miku_no_gekishou(int x, int y){
    int min = 1 << 31;
    int max = ~min;
    int sum = x + y;
    int negx = x >> 31;
    int negsum = sum >> 31;
    int overflow = (~(x ^ y) & (x ^ sum)) >> 31;
    return (~overflow & sum) | (~negx & (overflow & max)) | (negx & (overflow & min));
}

int caliburne_story_of_the_legendary_sword(unsigned x){
    unsigned var1, var2, bit7, bit5, bit;
    var1 = x >> 7;
    var2 = x >> 5;
    bit5 = (x & 0x1F);
    bit7 = (x & 0x7F) >> 2;
    bit = bit7 + bit5;

    return var1 + var2 + !!bit + (bit >> 5);
}

int oshama_scramble(unsigned uf){
    unsigned sign = uf >> 31;
    int e = (uf >> 23) & 0xFF;
    int mantissa = (uf & 0x7FFFFF) | 0x800000;
    int exp = e - 127;
    int bin;

    if(e == 0xFF){
        return 0x80000000u;
    }
    if(exp < 0){
        return 0;
    }
    else if(exp <= 23){
        bin = mantissa >> (23 - exp);
    }
    else if(exp <= 31){
        bin = mantissa << (exp - 23);
    }
    else{
        if(sign){
            return INT_MIN;
        }
        else{
            return INT_MAX;
        }
    if (sign){
        bin = -bin;
    }
    return (bin);
}
}

unsigned regulus(unsigned uf){
//     int sign = (uf >> 31) << 31;
//     int e = uf & 0x7F800000 >> 23;
//     int mantissa = uf & 0x7FFFFF;
//     int var = uf & 0x7FFFFFFF;

//     if(e >> 23 == 0xFF){
//         return uf;
//     }
//     else if (e >> 23 == 1){
        
//     }
//     else if(var >> 23 == 0){
//         return var << 1;
//     }// 0 0000 0001 0000 0000...
//     // 10.000
//     // 1.00
//     // exp = 1
//     // 0 0010 0000 000000000...
//     else{
//         if(e + 1 == 0xFF){
//             return sign | 0x7F800000;
//         }
//     }
// } SALAH

    int sign = uf & 0x80000000;
    int e = uf & 0x7F800000;
    int mantissa = uf & 0x7FFFFF;
    if(!e){
        return uf << 1 | sign;
    }
    else if(e >> 23 == 0xFF){
        return uf;
    }
    else{
        return sign | (((e >> 23) + 1) << 23) | mantissa;
    }

    // return uf + (1 << 23); //maybe correct
}

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

int garakuta_doll_play(unsigned x){
    int i, j, k, l, m, msb, lsb;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);

    // i = 0x55555555 
    i = 0x55 | (0x55 << 8); 
    i = i | (i << 16);

    // j = 0x33333333 
    j = 0x33 | (0x33 << 8);
    j = j | (j << 16);

    // k = 0x0f0f0f0f 
    k = 0x0f | (0x0f << 8);
    k = k | (k << 16);

    // l = 0x00ff00ff 
    l = 0xff | (0xff << 16);

    // m = 0x0000ffff 
    m = 0xff | (0xff << 8);

    x = (x & i) + ((x >> 1) & i);
    x = (x & j) + ((x >> 2) & j);
    x = (x & k) + ((x >> 4) & k);
    x = (x & l) + ((x >> 8) & l);
    x = (x & m) + ((x >> 16) & m);
    msb = x;

    lsb = x & (~x +1);

    return msb;
}

int f2i(char x){
    union{
        float f;
        int i;
        char c;
    } a;
    a.c = x;
    return a.i;
}


int main(){
    // float x = 123;
    // char x = 'B';
    // scanf("%d", &x);
    // printf("%c\n", x);
    // int y = f2i(x);
    // (int) x;
    // x += 2;
    // printf("%c", x);
    // int a = INT_MIN;
    // a = a >> 10;
    // // int a = 0xFF << 8;        
    // printf("%b\n",a);

    float x = 23.25;
    printf("%b\n", x);
    long j =  * ( long * ) &x;
    printf("%b\n", j);
    long i = (long) x;
    printf("%b", i);
    
    // int x = 0x61; // ONLY USEFUL FOR FLOAT
    // char c;
    // c = * ( char * ) &x;
    // printf("%c", x);
    return 0;
}

// x - y =
// x + (~y) + 1

    // int exp = ((uf << 1) >> 24);
    // int e = exp - 127;
    // int mantissa = uf & ((0x7F << 16) | (0xFF << 8) | 0xFF);
    // int front = (!!exp << e);
    // int sign = uf >> 31;
    // int res;

    // if (e<0){
    //     return 0;
    // }
    // else if(e<=23){
    //     res = (mantissa >> (23-e)) | front;
    // }
    // else if(e <=30){
    //     res = (mantissa << (e-23)) | front;
    // }
    // else{
    //     return 0x80000000u;
    // }
    // if (sign){
    //     return -res;
    // }
    // return res;

    // unsigned count = 0x4f800000;
    // unsigned tmp;
    // unsigned abs = uf;
    // unsigned last = 0;
    // if(uf < 0){
    //     count = 0xcf800000;
    //     abs = -uf;
    // }
    // while(abs){
    //     tmp = abs;
    //     abs <<= 1;
    //     count = count - 0x800000;
    //     if(tmp & 0x80000000){
    //     last = (abs & 0x3ff);
    //     if(last != 0x100){
    //         count = count + ((abs & 0x100) >> 8);
    //     }
    //     return (abs >> 9) + count;
    //     }
    // }
    // return 0;


// x
// -x
// ~x + 1
