#include <iostream>
//#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int tests;
	cin >> tests;
	
	for(; tests > 0; tests--) {
		int m, s;
		cin >> m >> s;
		
		bool nums[96] = {false};
		bool valid = true;
		int largest = 0;
		
		int b;
		for(; m > 0; m--) {
			cin >> b;
			if(nums[b]) valid = false;
			if(b > largest) largest = b;
			nums[b] = true;
		}
		if(!valid) {
			cout << "NO" << endl;
			continue;
		}
		
		int idx = 1;
		while(s > 0) {
			if(!nums[idx]) s -= idx;
			idx++;
		}
		while(idx < largest) {
			if(!nums[idx++]) {
				valid = false;
				break;
			}
		}
		
		if(s < 0 || !valid) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}