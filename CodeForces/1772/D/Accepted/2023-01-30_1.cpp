#include <iostream>
//#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int tests;
	cin >> tests;
	for(; tests > 0; tests--) {
		int n;
		cin >> n;
		
		int cmin = 0;
		int cmax = 0x7fffffff;
		
		int prev, curr;
		cin >> curr;
		n--;
		
		while(n-- > 0) {
			prev = curr;
			cin >> curr;
			
			if(prev == curr) {
				continue;
			} else if(prev < curr) {
				// ascending
				cmax = min(cmax, (prev + curr) / 2);
			} else {
				// descending
				cmin = max(cmin, (prev + curr + 1) / 2); // +1 has same effect as ceil()
			}
			if(cmin > cmax) break;
		}
		while(n-- > 0) cin >> curr;	// exhaust rest of input
		
		if(cmin > cmax) {
			cout << -1 << endl;
		} else {
			cout << cmin << endl;
		}
	}
	return 0;
}