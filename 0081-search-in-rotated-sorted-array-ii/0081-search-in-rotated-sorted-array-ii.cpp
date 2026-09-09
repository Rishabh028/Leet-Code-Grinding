class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        while (st <=end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
            }
            else if (nums[mid] >= nums[st]) {
                if(target < nums[mid] && target >= nums[st]) {
                    end = mid - 1;
                }
                else {
                    st = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
