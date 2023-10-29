class Solution {
public:
    bool isPalindrome(string s) {
        char *f = &s.front();
        char *b = &s.back();
        while(!isalnum(*f)) if(f++ >= &s.back()) return true;
        while(!isalnum(*b)) if(b-- <= &s.front()) return true;
        while(1) {
            if(tolower(*f) != tolower(*b)) return false;
            while(!isalnum(*++f)) if(f >= b) return true;
            while(!isalnum(*--b)) if(b <= f) return true;
        }
        return true;
    }
};