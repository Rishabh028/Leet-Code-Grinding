class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        

        int low = 0;
        int high = rows * cols - 1;

        while (low <= high) {
            int mid_idx = low + (high - low) / 2;
            
            int mid_val = matrix[mid_idx / cols][mid_idx % cols];

            if (mid_val == target) {
                return true; 
            } else if (mid_val < target) {
                low = mid_idx + 1;
            } else {
                high = mid_idx - 1;
            }
        }

        return false;
    }
};