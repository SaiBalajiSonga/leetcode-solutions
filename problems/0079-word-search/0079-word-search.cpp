class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i< m; i++){
            for(int j = 0; j< n ; j++){
                if(board[i][j] == word[0]){
                   if(dfs(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
    private:
        bool dfs(vector<vector<char>> &board, string& word,int i ,int c, int index){
            if(index == word.length()){
                return true;
            }

            if (i < 0 || i >= board.size() || c < 0 || c >= board[0].size() || board[i][c] != word[index]) {
            return false;
            }

            // Step 2: Track visited cell by saving its character and marking it
            char original_char = board[i][c];
            board[i][c] = '#'; // Temporarily mark as visited
            
            // Step 3: Recurse into all 4 surrounding directions (Up, Down, Left, Right)
            bool word_found = dfs(board, word, i + 1, c, index + 1) || // Down
                            dfs(board, word, i - 1, c, index + 1) || // Up
                            dfs(board, word, i, c + 1, index + 1) || // Right
                            dfs(board, word, i, c - 1, index + 1);   // Left
            
            // Step 4: Backtrack! Restore the original character for other starting loops
            board[i][c] = original_char;
            
            return word_found;
        }
};