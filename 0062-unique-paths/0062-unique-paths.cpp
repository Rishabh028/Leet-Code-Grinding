class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1; i<m; i++)
        {
            vector<int> temp(n,0);
            temp[0] = 1;
            for(int j=1; j<n; j++)
                temp[j] = temp[j-1] + dp[j];
            dp = temp;
        }
        return dp[n-1];
    }
};