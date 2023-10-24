#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

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