#include <iostream>

using namespace std;

#define ll long long

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    for(int tests = 1; tests <= t; tests++) {
        string alien, source, target;
        cin >> alien >> source >> target;
        int source_base = source.length();
        int target_base = target.length();
        
        
        ll total = 0LL;
        ll cur_pos = 1LL;
        for(int i = alien.length() - 1; i >= 0; i--) {
            char c = alien[i];
            int idx = -1;
            for(int j = 0; j < source_base; j++) {
                if(c == source[j]) {
                    idx = j;
                }
            }
            total += idx * cur_pos;
            cur_pos *= source_base;
        }
        
        string res;
        while(total > 0) {
            int idx = total % target_base;
            total /= target_base;
            res = target[idx] + res;
        }
        
        cout << "Case #" << tests << ": " << res << endl;
    }
    return 0;
}