class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        multiset<int> ms;

        int i = 0;
        int j = 0;
        while ( j < n) {
            auto up = ms.upper_bound(nums[j]);
            if ((up != ms.end() and *up-nums[j] <= valueDiff) || (up != ms.begin() and nums[j] - *(--up) <= valueDiff))
            return true;
            ms.insert(nums[j]);

            if (ms.size() == indexDiff + 1) {
                ms.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};