class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rs = 0;
        for (int x : nums) {
            rs ^= x;
        }
        return rs;
    }
};