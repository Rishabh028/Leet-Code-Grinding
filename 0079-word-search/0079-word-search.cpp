class Solution {
    private:
     int m , n;
     bool dfs(vector<vector<char>>& board, const string& word, int idx, int row, int col) {
        if (idx == word.length()) return true;
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[idx]) return false;
        char original = board[row][col];
        board[row][col] = '#';
        bool found = dfs(board, word, idx + 1, row + 1, col) ||
                     dfs(board, word, idx + 1, row - 1, col) ||
                     dfs(board, word, idx + 1, row, col + 1) ||
                     dfs(board, word, idx + 1, row, col - 1);
                     board[row][col] = original;
                     return found;
            }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};