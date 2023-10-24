int caliburne_story_of_the_legendary_sword(unsigned x){
    unsigned var1, var2, bit7, bit5, bit;
    var1 = x >> 7;
    var2 = x >> 5;
    bit5 = (x & 0x1F);
    bit7 = (x & 0x7F) >> 2;
    bit = bit7 + bit5;

    return var1 + var2 + !!bit + (bit >> 5);
}