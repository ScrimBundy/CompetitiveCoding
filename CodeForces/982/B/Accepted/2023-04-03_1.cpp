#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int n;
	cin >> n;
	
	vector<int> widths;
	unordered_map<int,int> um;
	for(int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		widths.push_back(temp);
		um.insert(make_pair(temp, i + 1));
	}
	
	string s;
	cin >> s;
	
	priority_queue<int, vector<int>, greater<int>> pq1(widths.begin(), widths.end());
	priority_queue<int> pq2;
	for(int i = 0; i < 2 * n; i++) {
		int w;
		if(s[i] == '0') {
			w = pq1.top();
			pq1.pop();
			pq2.push(w);
		} else {
			w = pq2.top();
			pq2.pop();
		}
		
		if(i != 0) {
			cout << " ";
		}
		cout << um.find(w)->second;
	}
	
	cout << endl;
	return 0;
}