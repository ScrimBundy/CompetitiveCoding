#include <iostream>
#include <string.h>


using namespace std;

int main(int argc, char *argv[]) {
	int tests;
	cin >> tests;
	for(; tests > 0; tests--) {
		int f,b;
		char c;
		cin >> f >> c >> b;
		cout << f + b << endl;
	}
	return 0;
}