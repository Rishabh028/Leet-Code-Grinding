class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;

        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            if(nums[i] >= firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if(nums[i] >= secondMax){
                thirdMax = secondMax;
                secondMax = nums[i];
            }
            else if(nums[i] > thirdMax)thirdMax = nums[i];
            if(nums[i] <= firstMin){
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if(nums[i] < secondMin){
                secondMin = nums[i];
            }
        }
        int a = firstMax*secondMax*thirdMax;
        int b = firstMax*firstMin*secondMin;
        return max(a , b);
    }
};