class Solution {
public:
    string reverseVowels(string s) {
        char* front = &s[0];
        char* back = &s[s.size() - 1];
        
        while(1) {
            while(front < back && !isVowel(*front)) front++;
            while(front < back && !isVowel(*back)) back--;
            
            if(front >= back) return s;
            
            char temp = *front;
            *front = *back;
            *back = temp;
            
            front++;
            back--;
        }
    }
private:
    bool isVowel(char ch) {
        // https://www.geeksforgeeks.org/program-find-character-vowel-consonant/
        return isalpha(ch) && (0x208222 >> (ch & 0x1f)) & 1;
    }
};