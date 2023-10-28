#include <iostream>
//#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int tests;
	cin >> tests;
	
	string y = "Yes";
	
	for(; tests > 0; tests--) {
		string s;
		cin >> s;
		
		int o;
		if(s[0] == 'Y') o = 0;
		else if(s[0] == 'e') o = 1;
		else if(s[0] == 's') o = 2;
		else {
			cout << "NO" << endl;
			continue;
		}
		
		bool valid = true;
		for(char c : s) {
			if(c != y[o++ % 3]) {
				valid = false;
				break;
			}
		}
		
		if(valid) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}