class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //search row
        int top = m - 1;
        int bot = 0;
        int mid;
        int row;
        
        while(top > bot) {
            mid = (top + bot) / 2;
            
            if(target == matrix[mid][0]) return true;
            
            if(target > matrix[mid][0] && target < matrix[mid+1][0]) {
                bot = mid; // potential containing row
                break;
            }
            if(target < matrix[mid][0]) {
                top = mid - 1;
            } else {
                // larger than both mid row and next row first
                bot = mid + 1;
            }
        }
        row = bot;
        
        top = n - 1;
        bot = 0;
        
        while(top >= bot) {
            mid = (top + bot) / 2;
            
            if(target == matrix[row][mid]) return true;
            
            if(target < matrix[row][mid]) 
                top = mid - 1;
            else 
                bot = mid + 1;
        }
        
        return false;
    }
};