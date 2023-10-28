#include <iostream>
#include <algorithm>

const int IMPOSSIBLE = 9001;

using namespace std;

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
        
        // for dp[j] entry is least days cleaning to clean j mess
        // overwritten for each day
        int *dp = new int[total_mess + 1];
        fill_n(dp, total_mess + 1, IMPOSSIBLE);
        
        // base case
        dp[0] = 0;
        
        // running totals
        int sum_mess = 0;
        int sum_clean = 0;
        
        // loop through days in interval
        for(int i = start_day; i < end_day; i++) {
            int clean = c[i];
            sum_mess += m[i];
            sum_clean += clean;
            
            // most mess cleanable by day i
            int idx = min(sum_mess, sum_clean);
            
            // Loop in reverse starting from most cleanable
            // Stop once no update is made
            // No updates will happen after this point anyway
            bool was_updated = true;
            do {
                // value currently held
                int old_val = dp[idx];
                
                /*
                 * dp[max(0, idx - clean)] + 1
                 *      checks the for the minimum number of required to clean
                 *      just enough that today we can use all the cleaning
                 *      today to get to idx amount cleaned
                 * update based on the best choice between this and the previous value
                 */
                int new_val = min(old_val, dp[max(0, idx - clean)] + 1);
                dp[idx] = new_val;
                
                // true if the value at idx changes
                //was_updated = old_val != new_val;
                
                // iterate backwards
                idx--;
            } while(idx > 0 && was_updated);
        }
        
        if(dp[total_mess] == IMPOSSIBLE) {
            total_cleaning_days = IMPOSSIBLE;
        } else {
            total_cleaning_days += dp[total_mess];
        }
        
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