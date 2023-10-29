class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int end = nums.size() - 1;
    
        // Make copy to avoid side effects
        vector<int> cnum(nums.size());
        copy(nums.begin(), nums.end(), cnum.begin());
        
        // sort copy
        sort(cnum.begin(), cnum.end());
    
        vector<vector<int>> r;
        // loop over lowest num
        for(int i = 0; i < end - 1; i++) {
            // make sure the next num used is unique to the last
            if(i > 0 && cnum[i - 1] == cnum[i]) continue;
            // invert num
            int inv = -1 * cnum[i];
            // if num is positive, adding two larger numbers will never be 0
            if(inv < 0) break;
            
            // outside in search of subset from i + 1 to n - 1
            int j = i + 1, k = end;
            while (j < k) {
                int sum = cnum[j]+cnum[k];
                if(sum < inv) j++;
                else if(sum > inv) k--;
                else {
                    // sum == inv
                    // sum + cnum[i] == 0
                    r.push_back({cnum[i],cnum[j],cnum[k]});
                    
                    // guarantee next solution is unique
                    while(j < k && cnum[j++] == cnum[j]);
                    while(j < k && cnum[k--] == cnum[k]);
                }
            }
        }
        return r;
    }
};