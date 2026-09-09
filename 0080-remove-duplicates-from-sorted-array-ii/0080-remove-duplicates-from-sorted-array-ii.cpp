class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int write = 0;

     for (int x : nums) {
        if (write < 2 || x != nums[write - 2]) {
            nums[write++] = x;
        }
     }   
     return write;
    }
};