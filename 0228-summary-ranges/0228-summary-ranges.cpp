class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return {};

        vector<string> ans;

        int start = 0, end = 0;
        while (end < size) {
            if (end == size - 1 || nums[end + 1] != nums[end] + 1) {
                if (start == end) {
                    ans.push_back(to_string(nums[start]));
                }
                else {
                    string temp = to_string(nums[start]) + "->" + to_string(nums[end]);
                    ans.push_back(temp);
                }
                start = end + 1;
            }
            end++;
        }
        return ans;
    }
};