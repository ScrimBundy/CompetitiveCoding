class Solution {
public:
    bool isValid(string s) {
        // Pushdown automata inspired
        stack<char> q;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') q.push(c);
            else {
                if(q.empty()) return false;
                
                char d;
                if(c == ')') d = '(';
                else if(c == '}') d = '{';
                else d = '[';
                
                if(q.top() == d) q.pop();
                else return false;
            }
        }
        return q.empty();
    }
};