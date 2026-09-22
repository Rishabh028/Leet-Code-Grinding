class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int length=1,max=1;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1 || nums[i]==nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                length++;
                }
                if(length>max) max=length;
            }
            else length=1;
        }

        return max;
    }
};