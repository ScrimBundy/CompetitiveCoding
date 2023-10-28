#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int len = s.size();
    
    // longest subsequence ending at index i
    int dp[len];
    // set all elements to 1
    fill_n(dp, len, 1);
    
    for(int i = 0; i < len; i++) {
        // loop through previous sequences
        for(int j = 0; j < i; j++) {
            // see if current letter can be added to previous sequence
            if(s[j] < s[i]) {
                // update max length sequence
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // Find max sequence
    int max_seq = 0;
    for(int i = 0; i < len; i++) {
        max_seq = max(max_seq, dp[i]);
    }
    
    // convert length of longest sequence to number of
    // letters required to make it the full alphabet
    int to_add = 26 - max_seq;
    cout << to_add << endl;
    
    return 0;
}