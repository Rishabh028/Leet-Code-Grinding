class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // Keep word2 as the shorter string to optimize space usage
        if (m < n) {
            return minDistance(word2, word1);
        }
        
        // dp array stores the edit distances for the previous row
        std::vector<int> dp(n + 1);
        for (int j = 0; j <= n; j++) {
            dp[j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            int prev = dp[0];
            dp[0] = i;  // Base case for converting word1[:i] to an empty string
            
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;  // Characters match, no operation needed
                } else {
                    // Choose minimum operation among: Delete, Insert, Replace
                    dp[j] = 1 + std::min({dp[j], dp[j - 1], prev});
                }
                prev = temp;
            }
        }
        
        return dp[n];
    }
};