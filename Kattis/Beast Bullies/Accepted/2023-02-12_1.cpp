#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define INT_MAX 0x7fffffff;

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    
    ll attack = a[0];
    ll defense = 0;
    int idx = 1;
    int result = 1;
    while(idx < n) {
        while(idx < n && defense < attack) {
            defense += a[idx];
            idx++;
        }
        if(defense < attack) break;
        attack += defense;
        defense = 0;
        result = idx;
    }
    
    cout << result << endl;
    return 0;
}