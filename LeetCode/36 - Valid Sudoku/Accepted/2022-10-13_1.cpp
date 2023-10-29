class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> col(9);
        vector<unordered_map<char, int>> box(9);
        for(int i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            for(int j = 0; j < 9; j++) {
                
                if(board[i][j] == '.') continue;
                
                // check row i
                if(row[board[i][j]] != 0) return false;
                else row[board[i][j]]++;
                
                // check box
                int box_num = (i/3)*3 + (j/3);
                if(box[box_num][board[i][j]] != 0) return false;
                else box[box_num][board[i][j]]++;
                
                // check column i
                if(col[j][board[i][j]] != 0) return false;
                else col[j][board[i][j]]++;
            }
        }
        return true;
    }
};