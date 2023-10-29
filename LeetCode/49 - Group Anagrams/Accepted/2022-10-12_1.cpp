class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        
        for(string s : strs) {
            
            // make histogram of string s
            int arr[26] = {0};
            for(char a : s) arr[a - 'a']++;
            
            // construct key string from histogram
            string n_str = "";
            for(int i = 0; i < 26; i++) {
                for(int j = arr[i]; j >= 0; j--) n_str += i+'a';
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