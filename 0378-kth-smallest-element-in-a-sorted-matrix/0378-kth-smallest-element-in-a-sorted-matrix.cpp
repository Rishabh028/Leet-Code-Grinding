class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arr(m * n);
        int cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                arr[cnt++] = matrix[i][j];
        return quickSelect(arr, 0, cnt - 1, k);
    }
private:
    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition(vector<int>& arr, int l, int r) {
        int pivot = l + (r - l) / 2;
        swap(arr, pivot, r);
        int placed = l;
        for (int i = l; i < r; ++i)
            if (arr[i] < arr[r])
                swap(arr, i, placed++);
        swap(arr, placed, r);
        return placed;
    }
    int quickSelect(vector<int>& arr, int l, int r, int k) {
        while (l < r) {
            int m = partition(arr, l, r);
            if (m == k - 1) break;
            else if (m < k - 1) l = m + 1;
            else r = m - 1;
        }
        return arr[k - 1];
    }
};