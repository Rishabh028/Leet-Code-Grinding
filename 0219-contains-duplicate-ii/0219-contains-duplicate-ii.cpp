class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.contains(nums[i]) && (i - hashmap[nums[i]]) <= k)
                return true;

            hashmap[nums[i]] = i;
        }

        return false;
    }
};
