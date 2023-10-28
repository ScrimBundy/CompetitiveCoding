#include <iostream>
using namespace std;

int main() {
	int tests, size, odd, even, tmp;
	cin >> tests;
	for (int i = 0; i < tests; i++) {
		cin >> size;
		odd = 0;
		even = 0;
		for (int j = 0; j < size; j++) {
			cin >> tmp;
			if (tmp % 2 == 0) {even++;}
			else {odd++;}
		}
		bool alice;
		switch(odd % 4) {
			case 1:
				alice = even % 2 == 1;
				break;
			case 2:
				alice = false;
				break;
			default:
				alice = true;
		}
		if (alice) {cout << "Alice\n";}
		else {cout << "Bob\n";}
	}
	return 0;
}