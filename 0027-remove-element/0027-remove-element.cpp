class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int r = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[r] = nums[i];
                r++;
            }
        }
        return r;
    }
};