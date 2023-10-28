#include <iostream>
#include <vector>
#include <algorithm>

const int IMPOSSIBLE = 9001;

using namespace std;

void dbgPrintArr(int *arr, int len) {
	for(int i = 0; i < len - 1; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[len - 1] << endl;
}

int main() {
	int n, d;
	cin >> n >> d;
	
	int m[n], c[n], v[d];
	for(int i = 0; i < n; i++) {
		cin >> m[i] >> c[i];
	}
	for(int i = 0; i < d; i++) {
		cin >> v[i];
	}
	
	// Running total of interval answers
	int total_cleaning_days = 0;
	
	// inclusive interval end index
	int start_day = 0;
	
	// loop through visit intervals
	// short circuit if any interval is impossible
	for(int visit = 0; visit < d && total_cleaning_days != IMPOSSIBLE; visit++) {
		
		// non-inclusive interval end index
		int end_day = v[visit];
		
		// find total mess within this interval
		int total_mess = 0;
		for(int i = start_day; i < end_day; i++) {
			total_mess += m[i];
		}
		
		// Two rows of the full DP matrix
		// dp0 represents even index rows
		// dp1 represents odd index rows
		// Full matrix is DP[days_in_interval][total_mess_in_interval]
		int *dp0 = new int[total_mess + 1];
		int *dp1 = new int[total_mess + 1];
		// Fill both arrays with marker value
		fill_n(dp0, total_mess + 1, IMPOSSIBLE);
		fill_n(dp1, total_mess + 1, IMPOSSIBLE);
		
		// base case
		dp0[0] = 0;
		
		// Only calculate up to this index
		int limit = min(m[start_day], c[start_day]);
		
		for(int i = 1; i <= limit; i++) {
			dp0[i] = 1;
		}
		
		// Running totals
		int sum_mess = m[start_day];
		int sum_clean = c[start_day];
		
		// pointers to dp arrays
		int *prev, *curr;
		
		// flag: true if dp1 should be modified next
		bool prev_dp0 = true;
		
		for(int i = start_day + 1; i < end_day; i++) {
			// Determine which array to modify
			if(prev_dp0) {
				prev = dp0;
				curr = dp1;
			} else {
				prev = dp1;
				curr = dp0;
			}
			// switch the flag
			prev_dp0 = !prev_dp0;
			
			int mess = m[i];
			int clean = c[i];
			sum_mess += mess;
			sum_clean += clean;
			
			// Only calculate up to this index
			// All values past are not possible
			limit = min(sum_mess, sum_clean);
			
			// Fill current dp array
			for(int j = 0; j <= limit; j++) {
				/*
				 * prev[max(0, j - clean)] + 1
				 * 		checks the previous array for the minimum number of
				 *      days required to clean just enough that today we can
				 *      use all the cleaning today to get to j amount cleaned
				 * prev[j]
				 *      use the previous best value for j mess
				 * minimum of the two is the optimal answer
				*/
				curr[j] = min(prev[max(0, j - clean)] + 1, prev[j]);
			}
		}
		
		// Retrieve the answer located at
		// dp[last_day][total_mess]
		int answer;
		if(prev_dp0) {
			answer = dp0[total_mess];
		} else {
			answer = dp1[total_mess];
		}
		
		if(answer == IMPOSSIBLE) {
			// interval is impossible, short circuit
			total_cleaning_days = IMPOSSIBLE;
		} else {
			// add answer to running sum
			total_cleaning_days += answer;
		}
		
		// clean up
		delete[] dp0;
		delete[] dp1;
		
		// Update start_day
		start_day = end_day;
	}
	
	// Print answer
	if(total_cleaning_days == IMPOSSIBLE) {
		cout << -1 << endl;
	} else {
		cout << total_cleaning_days << endl;
	}
	
	return 0;
}