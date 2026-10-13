class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int count=floor(nums.size()/3)+1;
        sort(nums.begin(),nums.end());
        vector<int>answer;
        int currentCount=1;
        int currentElement=nums[0];
        for(int i=1;i<nums.size();i++) {

            if(currentElement==nums[i]) {
                currentCount+=1;
            }else{
                if(currentCount>=count) {
                    answer.push_back(currentElement);
                }
                currentElement=nums[i];
                currentCount=1;
            }

        }
        if(currentCount>=count) {
            answer.push_back(currentElement);
        }
    
        return answer;

    }
};