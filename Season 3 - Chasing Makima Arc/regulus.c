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