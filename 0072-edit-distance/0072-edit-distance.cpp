class Solution {
public:
    int solve(string &word1,string &word2, int i, int j, vector<vector<int>>&dp){
        int n = word1.size();
        int m = word2.size();
        if(i==n) return m-j;
        if(j==m)return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int same = 1e8, replace = 1e8, insert =1e8, remove = 1e8;
        if(word1[i] == word2[j]){
            same = solve(word1, word2, i+1, j+1,dp);
        }
        else{
            remove = 1+solve(word1, word2, i+1, j,dp);
            replace = 1+solve(word1, word2, i+1, j+1,dp);
            insert = 1+solve(word1, word2, i, j+1,dp);
        }
        return dp[i][j] = min({same, remove, insert, replace});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve( word1, word2, 0,0,dp);
    }
};