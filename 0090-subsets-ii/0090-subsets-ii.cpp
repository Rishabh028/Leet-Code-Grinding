class Solution {
private:
    void generate(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int i) {
        subsets.push_back(subset);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }
            subset.push_back(nums[j]);
            generate(nums, subsets, subset, j + 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;
        generate(nums, subsets, subset, 0);
        return subsets;
    }
};