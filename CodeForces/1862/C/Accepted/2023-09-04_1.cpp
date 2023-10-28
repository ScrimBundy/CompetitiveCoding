#include <iostream>
#include <vector>

using namespace std;

vector<int> func(vector<int> vec);
vector<int> func2(vector<int> vec);
bool compare(vector<int> first, vector<int> second);
bool isPalindrome(vector<int> vec);
void printVec(vector<int> vec);

int main() {

	int tests;
	cin >> tests;
	
	for(int test = 0; test < tests; test++) {
		
		int length;
		cin >> length;
		
		vector<int> fence(length);
		for(int i = 0; i < length; i++) {
			cin >> fence[i];
		}
		
		vector<int> outline = func2(fence);
		//printVec(outline);
		
		if(isPalindrome(outline)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}

}

vector<int> func(vector<int> vec) {
	int length = vec.size();
	int first = vec[0];
	vector<int> inv(first);
	int ptr = 0;
	for(int i = 0; i < vec[length - 1]; i++) {
		inv[ptr] = length;
		ptr++;
	}
	for(int i = length - 2; i >= 0; i--) {
		length--;
		int diff = vec[i] - vec[i+1];
		if(diff > 0) {
			for(int i = 0; i < diff; i++) {
				inv[ptr] = length;
				ptr++;
			}
		}
	}
	return inv;
}

vector<int> func2(vector<int> vec) {
	vector<int> outline;
	int width = 1;
	for(int i = 0; i < vec.size(); i++) {
		int next;
		if(i == vec.size() - 1) {
			next = 0;
		} else {
			next = vec[i+1];
		}
		
		if(vec[i] == next) {
			width++;
			continue;
		}
		
		outline.push_back(width);
		outline.push_back(vec[i] - next);
		width = 1;
	}
	
	return outline;
}

bool compare(vector<int> first, vector<int> second) {
	if(first.size() != second.size()) return false;
	for(int i = 0 ; i < first.size(); i++) {
		if(first[i] != second[i]) return false;
	}
	return true;
}

bool isPalindrome(vector<int> vec) {
	return equal(begin(vec), begin(vec) + size(vec)/2, rbegin(vec));
}

void printVec(vector<int> vec) {
	for(int i = 0; i < vec.size() - 1; i++) {
		cout << vec[i] << " ";
	}
	cout << vec[vec.size() - 1] << endl;
}