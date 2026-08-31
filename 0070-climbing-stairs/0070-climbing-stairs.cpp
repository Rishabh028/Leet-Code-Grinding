class Solution {
public:

int f( int n ){
        int prev1 = 1;
        int prev2 = 0;
        for( int i = 1; i <= n ; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
            return prev1;
    }

    int climbStairs(int n) {


        return f(n);
    }
};