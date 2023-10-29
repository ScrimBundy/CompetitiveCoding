class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        // credit: https://graphics.stanford.edu/~seander/bithacks.html#BitReverseTable
        
        uint32_t r;
        
        uint8_t *p = (uint8_t *) &n;
        uint8_t *q = (uint8_t *) &r;
        q[3] = BitReverseTable256[p[0]];
        q[2] = BitReverseTable256[p[1]];
        q[1] = BitReverseTable256[p[2]];
        q[0] = BitReverseTable256[p[3]];
        
        return r;
    }
private:
    static constexpr uint8_t BitReverseTable256[256] = 
    {
    #   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
    #   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
    #   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
        R6(0), R6(2), R6(1), R6(3)
    };
};