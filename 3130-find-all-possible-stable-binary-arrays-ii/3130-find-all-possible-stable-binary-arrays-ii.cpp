int mod=1e9+7;
int dp[1001][1001][2];
int pre[1001][1001][2];
class Solution {
public:

int numberOfStableArrays(int zero, int one, int limit) {
    dp[0][0][0]=1;dp[0][0][1]=1;
    pre[0][0][0]=1;pre[0][0][1]=1;
    for (int i=0;i<=zero;i++){
        for (int j=0;j<=one;j++){
            if (i==0 && j==0) continue;
            if (j>0) dp[i][j][0]=(pre[i][j-1][1]-((j-min(limit,j)-1>=0)? pre[i][j-min(limit,j)-1][1]:0)+mod)%mod;
            if (i>0) dp[i][j][1]=(pre[i-1][j][0]-((i-min(i,limit)-1>=0)?pre[i-min(i,limit)-1][j][0]:0)+mod)%mod;
            pre[i][j][0]=(((i>0)? pre[i-1][j][0]:0)+dp[i][j][0])%mod;
            pre[i][j][1]=(((j>0)? pre[i][j-1][1]:0)+dp[i][j][1])%mod;
        }
    }
    return (dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};