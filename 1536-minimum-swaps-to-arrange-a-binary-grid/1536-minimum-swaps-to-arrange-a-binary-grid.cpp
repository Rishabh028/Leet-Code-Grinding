class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);
        for (int i = 0; i < n; ++i) {
            int cnt = 0, j = n-1;
            while (j >= 0 && grid[i][j] == 0) {
                cnt++;
                j--;
            }
            zeros[i] = cnt;
        }
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && zeros[j] < need) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(zeros[j], zeros[j-1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};