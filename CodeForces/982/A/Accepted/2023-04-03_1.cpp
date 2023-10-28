#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
	cin >> n;
	string s;
	cin >> s;
	
	int zeros_in_a_row = 1;
	bool maximal = true;
	
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			zeros_in_a_row++;
			if(zeros_in_a_row == 3) {
				maximal = false;
			}
		} else {
			if(zeros_in_a_row == 0) {
				maximal = false;
			}
			zeros_in_a_row = 0;
		}
	}
	
	if(zeros_in_a_row == 2)
		maximal = false;
	
	if(maximal) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}