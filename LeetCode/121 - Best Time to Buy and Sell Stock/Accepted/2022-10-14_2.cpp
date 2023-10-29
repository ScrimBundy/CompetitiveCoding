class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int diff = INT_MIN;
        for(int n : prices) {
            if (n < min) min = n;
            diff = max(diff,n-min);
        }
        return diff;
    }
};