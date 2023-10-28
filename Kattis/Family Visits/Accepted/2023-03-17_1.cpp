#include <iostream>
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
    
    int total_cleaning_days = 0;
    
    int start_day = 0;
    for(int visit = 0; visit < d && total_cleaning_days != IMPOSSIBLE; visit++) {
        int end_day = v[visit];
        
        int total_mess = 0;
        for(int i = start_day; i < end_day; i++) {
            total_mess += m[i];
        }
        
        int *dp0 = new int[total_mess + 1];
        int *dp1 = new int[total_mess + 1];
        fill_n(dp0, total_mess + 1, IMPOSSIBLE);
        fill_n(dp1, total_mess + 1, IMPOSSIBLE);
        
        dp0[0] = 0;
        
        int limit = min(m[start_day], c[start_day]);
        
        for(int i = 1; i <= limit; i++) {
            dp0[i] = 1;
        }
        
        int sum_mess = m[start_day];
        int sum_clean = c[start_day];
        
        int *prev, *curr;
        bool prev_dp0 = true;
        
        for(int i = start_day + 1; i < end_day; i++) {
            if(prev_dp0) {
                prev = dp0;
                curr = dp1;
            } else {
                prev = dp1;
                curr = dp0;
            }
            prev_dp0 = !prev_dp0;
            
            int mess = m[i];
            int clean = c[i];
            sum_mess += mess;
            sum_clean += clean;
            
            limit = min(sum_mess, sum_clean);
            
            for(int j = 0; j <= limit; j++) {
                curr[j] = min(prev[max(0, j - clean)] + 1, prev[j]);
            }
        }
        
        int answer;
        if(prev_dp0) {
            answer = dp0[total_mess];
        } else {
            answer = dp1[total_mess];
        }
        
        if(answer == IMPOSSIBLE) {
            total_cleaning_days = IMPOSSIBLE;
        } else {
            total_cleaning_days += answer;
        }
        
        delete[] dp0;
        delete[] dp1;
        
        start_day = end_day;
    }
    
    if(total_cleaning_days == IMPOSSIBLE) {
        cout << -1 << endl;
    } else {
        cout << total_cleaning_days << endl;
    }
    
    return 0;
}