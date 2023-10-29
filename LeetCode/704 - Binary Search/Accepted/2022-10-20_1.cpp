class Solution {
public:
    int search(vector<int>& nums, int target) {
        int top = nums.size() - 1;
        int bot = 0;
        int mid;
        while (top >= bot) {
            mid = (top + bot) / 2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < target)
                bot = mid + 1;
            else
                top = mid - 1;
        }
        
        return -1;
    }
};