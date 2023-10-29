class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Guard clause to check for equivalent length
        if (s.length() != t.length()) return false;
        
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;
        for(int i = 0; i < s.length(); i++) {
            updateMap(s_map, s.at(i));
            updateMap(t_map, t.at(i));
        }
        return s_map == t_map;
    }
    void updateMap(unordered_map<char,int> &map, char c) {
        if(map.find(c) != map.end()) {
            map[c]++;
        } else {
            map[c] = 1;
        }
        return;
    }
};