class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Deep copy to prevent side effects
        vector<int> copy = nums;
        // Sort the copy
        sort(copy.begin(), copy.end());
        
        bool dup = false;
        
        int r = copy[0];
        for(int i = 1; i < copy.size(); i++) {
            if (r == copy[i]) {
                dup = true;
                break;
            }
            r = copy[i];
        }
        
        // Clean up
        copy.clear();
        return dup;
    }
};