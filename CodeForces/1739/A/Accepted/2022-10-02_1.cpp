#include <iostream>
using namespace std;

void check(int n, int m);

int main() {
	int tests = 0;
	cin >> tests;
	while (tests-- > 0) {
		int n = 0;
		int m = 0;
		cin >> n;
		cin >> m;
		check(n,m);
	}
	return 0;
}

void check(int n, int m) {
	if (n == 3 && m == 3) {
		cout << "2 2\n";
	} else if (n == 2 && m == 3) {
		cout << "1 2\n";
	} else if (n == 3 && m == 2) {
		cout << "2 1\n";
	} else {
		cout << "1 1\n";
	}
}