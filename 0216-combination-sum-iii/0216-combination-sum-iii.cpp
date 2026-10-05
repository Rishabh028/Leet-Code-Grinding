class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int k, int target, int start, vector<int>& path) {
        if (target == 0 && k == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; ++i) {
            if (i > target || k <= 0) break;
            path.push_back(i);
            backtrack(k - 1, target - i, i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtrack(k, n, 1, path);
        return res;
    }
};