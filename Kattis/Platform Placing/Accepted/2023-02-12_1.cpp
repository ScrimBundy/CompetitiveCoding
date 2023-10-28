#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define INT_MAX 0x7fffffff;

using namespace std;

int main(int argc, char *argv[]) {
    int n, s, k;
    cin >> n >> s >> k;
    
    vector<int> fp(n);
    vector<int> dist(n + 1);
    
    for(int i = 0; i < n; i++) {
        cin >> fp[i];
    }
    
    sort(fp.begin(), fp.end());
    
    bool impossible = false;
    
    dist[0] = INT_MAX;
    dist[n] = INT_MAX;
    for(int i = 1; i < n; i++) {
        int tempdist = fp[i] - fp[i - 1];
        if(tempdist < s) {
            impossible = true;
            break;
        }
        dist[i] = tempdist * 2; // avoid /2 strangeness
    }
    
    if(impossible) {
        cout << -1 << endl;
        return 0;
    }
    
    int total = 0;
    for(int i = 0; i < dist.size() - 1; i++) {
        int platLen = min(min(dist[i], dist[i + 1] - s) , k);
        dist[i + 1] -= platLen;
        total += platLen;
    }
    
    cout << total << endl;
    
    return 0;
}