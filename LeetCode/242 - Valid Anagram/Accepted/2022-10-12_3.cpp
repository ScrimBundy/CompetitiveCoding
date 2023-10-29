class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Guard clause to check for equivalent length
        if (s.length() != t.length()) return false;
        
        // array of zeros
        int count[26] = {0};
        
        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int e : count) {
            if(e != 0) return false;
        }
        return true;
    }
};