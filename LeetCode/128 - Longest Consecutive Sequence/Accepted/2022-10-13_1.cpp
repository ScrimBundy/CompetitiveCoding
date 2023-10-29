class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        int max = 0;
        for(int n : s) {
            if(s.count(n-1) == 0) {
                int c = 1;
                while(s.count(++n) != 0) {
                    c++;
                }
                if (c>max) max=c;
            }
        }
        return max;
    }
};