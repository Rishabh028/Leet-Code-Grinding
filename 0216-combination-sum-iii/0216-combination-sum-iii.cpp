class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int start, int k, int target) {
        if (k == 0) {
            if (target == 0)
                ans.push_back(path);

            return;
        }

        for (int x = start; x <= 9; x++) {
            if (x > target)
                break;

            path.push_back(x);

            dfs(x + 1, k - 1, target - x);

            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};