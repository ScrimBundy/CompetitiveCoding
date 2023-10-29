class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        
        for(string s : strs) {
            
            // make histogram of string s
            std::map<char, int> h;
            for(char a : s) h[a]++;
            string key = "";
            for(auto& v : h) {
                key += v.first;
                key += v.second;
            }
            
            // search map for key string, add if failed
            if(map.find(key) != map.end()) {
                map[key].push_back(s);
            } else map[key] = {s};
        }
        
        // convert map into vector, discarding keys
        vector<vector<string>> r;
        for(auto& v : map) {
            r.push_back(v.second);
        }
        
        return r;
    }
};