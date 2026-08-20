class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector <int>> mtx(n, vector <int> (n));

        function <void(int, int, int)> gen = [&](int row, int col, int cur) {
            if (row >= (n + 1) / 2 or col >= (n + 1) / 2)
                return;
            
            for (int i = col; i < n - col; i++)
                mtx[row][i] = cur++;
            
            for (int i = row + 1; i < n - row; i++)
                mtx[i][n - col - 1] = cur++;
            
            if (row == n / 2 or col == n / 2)
                return;
            
            for (int i = n - col - 2; i > col; i--)
                mtx[n - row - 1][i] = cur++;
            
            for (int i = n - row - 1; i > row; i--)
                mtx[i][col] = cur++;
            
            gen(row + 1, col + 1, cur);
        };

        gen(0, 0, 1);

        return mtx;
    }
};