class Solution {
public:
    bool isValid(string s) {
        char stk[s.length()];
        int stk_index = 0;
        for(int i = 0; i < s.length(); i++) {
            if      (s[i] == '(') stk[stk_index++] = ')';
            else if (s[i] == '[') stk[stk_index++] = ']';
            else if (s[i] == '{') stk[stk_index++] = '}';
            else if (stk_index == 0) return false;
            else if (s[i] == stk[--stk_index]) NULL;
            else return false;
        }
        return stk_index == 0;
    }
};