class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // n
        int sz = nums.size();
        
        // xor of all numbers from 0 to n
        int xor_zn = 0;
        switch(sz % 4) {
            case 0:
                xor_zn = sz;
                break;
            case 1:
                xor_zn = 1;
                break;
            case 2:
                xor_zn = sz + 1;
                break;
            default:
                xor_zn = 0;
        }
        
        for(int i : nums) {
            xor_zn ^= i;
        }
        
        return xor_zn;
    }
};