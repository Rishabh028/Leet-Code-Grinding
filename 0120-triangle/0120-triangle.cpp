class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (m, INT_MAX));
        dp[0][0] = triangle[0][0];

        if (m == 1){
            return dp[0][0];
        }
        int result = INT_MAX;

        for (int r = 1; r < m; r++) {
            for (int c = 0; c <= r; c++){
                if (c > 0) {
                    dp[r][c] = triangle[r][c] + dp[r - 1][c - 1];
                }
                if (c != r) {
                    dp[r][c] = min(dp[r][c], dp[r - 1][c] + triangle[r][c]);
                }
                if (r == (m - 1)) {
                    result = min (result, dp[r][c]);
                }
            }
        }
        return result;
    }
};