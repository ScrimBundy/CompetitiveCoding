#include <iostream>
#include <vector>
#include <algorithm>

const int IMPOSSIBLE = 9001;

using namespace std;

bool same_letters(string s, string t) {
	sort(s.begin(), s.end());
    sort(t.begin(), t.end());
	
	return s == t;
}

int main() {
    int tests;
    cin >> tests;
	
	for(int test = 0; test < tests; test++) {
		int n, k;
		cin >> n >> k;
		string s, t;
		cin >> s >> t;
		
		if(s == t) {
			cout << "YES" << endl;
			continue;
		}
		
		if(same_letters(s, t)) {
			if(n >= 2 * k) {
				cout << "YES" << endl;
			} else if(n <= k) {
				cout << "NO" << endl;
			} else {
				int outside_sz = (n - k);
				int middle_sz = n - outside_sz * 2;
				bool same = true;
				for(int i = outside_sz; i < outside_sz + middle_sz; i++) {
					if(s[i] != t[i]) {
						same = false;
					}
				}
				if(same) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			}
		} else {
			cout << "NO" << endl;
		}
	}
    
}