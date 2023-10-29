class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool col[9][9] = {false};
        bool box[9][9] = {false};
        for(int i = 0; i < 9; i++) {
            bool row[9] = {false};
            for(int j = 0; j < 9; j++) {
                
                int v = board[i][j];
                if(v == '.') continue;
                
                v -= '1';
                
                // check row i
                if(row[v]) return false;
                else row[v] = true;
                
                // check box
                int box_num = (i/3)*3 + (j/3);
                if(box[box_num][v]) return false;
                else box[box_num][v] = true;
                
                // check column i
                if(col[j][v]) return false;
                else col[j][v] = true;
            }
        }
        return true;
    }
};