class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
private:
    bool solve(vector<vector<char>>& board){
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    for (char val = '1'; val <= '9'; ++val){
                        if (isValid(board, r, c, val)) {
                            board[r][c] = val; // Tentatively place it
                            
                            // Recursively try to solve the rest of the board
                            if (solve(board)) {
                                return true; // If it worked, we are done!
                            }
                            
                            // Backtrack! If it didn't work out, erase it and try next number
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char val){
        for (int i = 0; i < 9; ++i) {
            // 1. Check the entire row
            if (board[row][i] == val) return false;
            
            // 2. Check the entire column
            if (board[i][col] == val) return false;
            
            // 3. Check the 3x3 sub-box using our math trick
            // rowBox finds the top of the 3x3 grid, + i / 3 moves down its rows
            // colBox finds the left of the 3x3 grid, + i % 3 moves across its columns
            int rowBox = 3 * (row / 3) + i / 3;
            int colBox = 3 * (col / 3) + i % 3;
            if (board[rowBox][colBox] == val) return false;
        }
        return true;
    }
};