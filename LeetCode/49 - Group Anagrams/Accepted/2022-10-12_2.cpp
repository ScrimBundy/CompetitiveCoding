class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        
        for(string s : strs) {
            
            // make histogram of string s
            unordered_map<char, int> h;
            for(char a : s) h[a]++;
            
            // construct key string from histogram
            string n_str = "";
            for(int i = 'a'; i <= 'z'; i++) {
                for(int j = h[i]; j >= 0; j--) n_str += i+'a';
            }
            
            // search map for key string, add if failed
            if(map.find(n_str) != map.end()) {
                map[n_str].push_back(s);
            } else map[n_str] = {s};
        }
        
        // convert map into vector, discarding keys
        vector<vector<string>> r;
        for(auto& v : map) {
            r.push_back(v.second);
        }
        
        return r;
    }
};