class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        int start = 0;

        for (int i = 0; i < n; i++) {
         
            if (i == n - 1 ||
                (long long)nums[i + 1] - nums[i] != 1) {

                if (start == i) {
                    ans.push_back(to_string(nums[start]));
                } else {
                    ans.push_back(to_string(nums[start]) + "->" +
                                  to_string(nums[i]));
                }

                start = i + 1;
            }
        }

        return ans;
    }
};