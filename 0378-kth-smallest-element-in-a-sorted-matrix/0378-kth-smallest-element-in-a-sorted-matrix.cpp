class Solution {
using ll = long long;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        ll n = matrix.size();
        auto f = [&](ll m) {
            ll r = n - 1;
            ll cnt = 0;
            ll c = 0;
            while(r >= 0 and c < n) {
                if(matrix[r][c] <= m) {
                    cnt += (r + 1);
                    c++;
                } else {
                    r--;
                }
            }
            return cnt;
        };
        ll lo = matrix[0][0];
        ll hi = matrix[n - 1][n - 1];
        while(lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            ll t = f(mid);
            if(t < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};