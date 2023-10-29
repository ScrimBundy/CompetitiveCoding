class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int u = 0;
        int v = n/2;
        
        // make sure min is in the cyclic arc from u to v inclusive
        if(nums[u] < nums[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        
        while(u != v) {
            // find half way index accounting for cyclic set
            int half;
            if(u > v)
                half = (n + v) - u;
            else
                half = v - u;
            half = (u + half / 2);
            
            // half %= n
            if(half >= n)
                half -= n;
            
            // base case
            if(half == u)
                return nums[v];
            
            // partition space
            if(nums[half] > nums[u])
                u = half;
            else
                v = half;
        }
        
        // case n = 2
        return nums[u];
    }
};