class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        
        unordered_set<char> m;
        
        int i = 0;
        int j = 0;
        
        int max_len = 0;
        
        while(j < n) {
            if(m.find(s[j]) == m.end()) {
                m.insert(s[j]);
                max_len = max(max_len, j - i + 1);
                j++;
            } else {
                m.erase(s[i]);
                i++;
            }
        }
        return max_len;
    }
};