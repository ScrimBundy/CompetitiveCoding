class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> r(2);
        for(int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if(map.find(c) != map.end()) {
                r[0] = map[c];
                r[1] = i;
                break;
            } else {
                map.insert({nums[i], i});
            }
        }
        return r;
    }
};