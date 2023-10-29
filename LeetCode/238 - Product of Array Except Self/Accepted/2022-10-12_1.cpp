class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size(), 1);
        int f = 1;
        int b = 1;
        for(int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            // multiply by prefix
            r[i] *= f;
            // multiply by suffix
            r[j] *= b;
            // update prefix and suffix
            f *= nums[i];
            b *= nums[j];
        }
        return r;
    }
};