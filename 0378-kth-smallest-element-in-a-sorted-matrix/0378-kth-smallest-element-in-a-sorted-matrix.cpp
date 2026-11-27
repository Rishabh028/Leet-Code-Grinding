class Solution {
public:
    int countElements(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        int count = 0, row = n - 1, col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countElements(matrix, mid);

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};