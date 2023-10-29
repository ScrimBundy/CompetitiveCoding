class Solution {
public:
    int climbStairs(int n) {
        
        // answer is (n+1)th fibbonacci number
        
        if(n == 1) return 1;
        //if(n == 2) return 2;
        
        // fib(2);
        long int k = 1;
        // fib(3)
        long int m = 2;
        
        // fibbonacci index
        n++;
        // 1 bit set shifted 1 right of msb of n
        int mask = 1 << (30 - __builtin_clz(n));
        
        // O(logn)
        while(mask > 1) {
            if(n & mask) {
                // + 1
                int temp = m;
                m += k;
                k = temp;
            }
            // * 2
            // Fast Doubling method
            long int temp = k;
            k *= (2 * m) - k;
            m = temp * temp + m * m;
            
            mask >>= 1;
        }
        
        if(n & mask) return (int)m;
        return (int)k;
    }
};