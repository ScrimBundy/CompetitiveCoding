#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
	int tests;
	cin >> tests;
	for(; tests > 0; tests--) {
		int k,n;
		cin >> k >> n;
		int diff = n - k;
		int last = 1;
		int c = 0;
		
		cout << 1 << " ";
		k--;
		
		while (k > 1 && c <= diff) {
			last++;
			diff -= c;
			last += c++;
			k--;
			cout << last << " ";
		}
		last += diff;
		while (k-- > 1) {
			cout << ++last << " ";
		}
		cout << n << endl;
	}
}