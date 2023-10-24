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