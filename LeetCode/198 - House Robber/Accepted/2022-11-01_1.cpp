class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0] + nums[2], nums[1]);
        
        int skip2 = nums[0];
        int skip1 = nums[1];
        int prev = nums[2] + skip2;
        int high = max(skip1, prev);
        
        for(int i = 3; i < n; i++) {
            int v = nums[i] + max(skip1, skip2);
            if(v > high) high = v;
            skip2 = skip1;
            skip1 = prev;
            prev = v;
        }
        
        return high;
    }
};