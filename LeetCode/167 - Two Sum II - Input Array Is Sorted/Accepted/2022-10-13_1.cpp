class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int *first = &numbers.front();
        int first_off = 0;
        int *second = &numbers.back();
        int second_off = 0;
        while(1) {
            int sum = *(first + first_off) + *(second - second_off);
            if(sum == target) {
                return vector<int>{first_off + 1, (int)numbers.size() - second_off};
            }
            else if(sum > target) second_off++;
            else first_off++;
        }
    }
};