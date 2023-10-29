class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Guard clause to check for equivalent length
        if (s.length() != t.length()) return false;
        
        vector<int> letter_count(26);
        for(int i = 0; i < s.length(); i++) {
            letter_count[s.at(i) - 'a']++;
            letter_count[t.at(i) - 'a']--;
        }
        for(int e : letter_count) {
            if(e != 0) return false;
        }
        return true;
    }
};