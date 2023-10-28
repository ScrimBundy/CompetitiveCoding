#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
	int tests;
	cin >> tests;
	for(; tests > 0; tests--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		
		/*
			This is functionally identical to the following boolean expression.
			(a < b && a < c && d > b && d > c) ||	// 0 ops
			(c < a && c < d && b > a && b > d) ||	// 1 op
			(d < b && d < c && a > b && a > c) ||	// 2 ops
			(b < a && b < d && c > a && c > d)		// 3 ops
			
			This abuses the "distinct integers" property of the input to reduce
			the total number of comparisons to just 4. Then reduce variable
			accesses by combining all 4 into an integer.
		*/
		
		int abcd = ((a < b) << 3) | ((a < c) << 2) | ((b < d) << 1) | (c < d);
		if(abcd == 0b1111 || abcd == 0b0110 || abcd == 0b0000 || abcd == 0b1001) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}