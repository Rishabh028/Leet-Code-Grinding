class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ranges::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater{});
        return nums[k - 1];
    }
};