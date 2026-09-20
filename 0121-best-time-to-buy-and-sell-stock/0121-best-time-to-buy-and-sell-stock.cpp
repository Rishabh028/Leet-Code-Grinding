class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices[0];
        int max = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            if (prices[i] < s) {
                s = prices[i];
            }
            else {
                if (prices[i] - s > max) {
                    max = prices[i] - s;
                }
            }
        }
        return max;
    }
};