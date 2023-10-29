class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size();
        
        if(sz - k + 1 < k) {
            k = sz - k + 1;
            priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
            
            while(k-- > 1) {
                pq.pop();
            }
            
            return pq.top();
        } else {
            priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());
            
            while(k-- > 1) {
                pq.pop();
            }
            
            return pq.top();
        }
        
        
    }
};