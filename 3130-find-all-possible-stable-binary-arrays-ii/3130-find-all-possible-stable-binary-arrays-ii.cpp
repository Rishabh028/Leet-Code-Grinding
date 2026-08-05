class Solution {
public:
    int dp[1001][1001][2];
    int numberOfStableArrays(int zero, int one, int limit) {
        for (int z = 0; z <= zero && z <= limit; z++) {
            dp[z][0][0] = 1;
        }
        for (int o = 0; o <= one && o <= limit; o++) {
            dp[0][o][1] = 1;
        }
        for (int z = 1; z <= zero; z++) {
            for (int o = 1; o <= one; o++) {
                dp[z][o][0] = (dp[z-1][o][0] + dp[z-1][o][1]) % 1000000007;
                if (z > limit) {
                    dp[z][o][0] = (dp[z][o][0] + 1000000007 - dp[z-limit-1][o][1]) % 1000000007;
                }
                dp[z][o][1] = (dp[z][o-1][0] + dp[z][o-1][1]) % 1000000007;
                if (o > limit) {
                    dp[z][o][1] = (dp[z][o][1] + 1000000007 - dp[z][o-limit-1][0]) % 1000000007;
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % 1000000007;
    }
};