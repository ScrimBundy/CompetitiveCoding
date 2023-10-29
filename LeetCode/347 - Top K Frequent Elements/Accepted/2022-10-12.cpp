class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
        vector<int> r;
        
        for(int n : nums) map[n]++;
        for(auto& v : map) q.push({v.second, v.first});
        for(int i = 0; i < k; i++) {
            r.push_back(q.top().second);
            q.pop();
        }
        return r;
    }
};