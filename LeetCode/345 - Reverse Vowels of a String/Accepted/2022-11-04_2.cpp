class Solution {
public:
    string reverseVowels(string s) {
        char* front = &s[0];
        char* back = &s[s.size() - 1];
        string vowels = "aeiouAEIOU";
        
        while(1) {
            while(front < back && vowels.find(*front) == string::npos) front++;
            while(front < back && vowels.find(*back) == string::npos) back--;
            
            if(front >= back) return s;
            
            char temp = *front;
            *front = *back;
            *back = temp;
            
            front++;
            back--;
        }
    }
};