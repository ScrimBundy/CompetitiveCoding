#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    long long n, m;
    cin >> n >> m;
    long long rungs[m];
    for(int i = 0; i < m; i++) {
        cin >> rungs[i];
    }
    int r[n];
    for(int i = 0; i < n; i++) {
        r[i] = i + 1;
    }
    
    for(int i = 0; i < m; i++) {
        // swap elements of r connected by rung i
        int temp = r[rungs[i] - 1];
        r[rungs[i] - 1] = r[rungs[i]];
        r[rungs[i]] = temp;
    }
    
    for (int i = 0; i < n; i++) {
        cout << r[i] << endl;
    }
    return 0;
}