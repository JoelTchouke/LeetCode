uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++)
    {
        res <<= 1U; 
        res |= (n & 1U); 
        n >>= 1U; 
    }
    return res;
}
