class Solution {
public:
    bool isPalindrome(string s) {
        char *f = &s.front();
        char *b = &s.back();
        while(1) {
            while(!isalnum(*f)) if(f++ >= &s.back()) return true;
            while(!isalnum(*b)) if(b-- <= &s.front()) return true;
            if(tolower(*f) != tolower(*b)) return false;
            f++;
            b--;
        }
        return true;
    }
};