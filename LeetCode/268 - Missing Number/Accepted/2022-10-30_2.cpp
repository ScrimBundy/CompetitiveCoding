class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        // xor of all numbers from 0 to n
        int xor_zn = n & 0b11; // n % 4
        if(xor_zn == 0b00)
            xor_zn = n;
        else if(xor_zn == 0b01)
            xor_zn = 1;
        else if(xor_zn == 0b10)
            xor_zn = n + 1;
        else
            xor_zn = 0;
        
        for(int i : nums) {
            xor_zn ^= i;
        }
        
        return xor_zn;
    }
};