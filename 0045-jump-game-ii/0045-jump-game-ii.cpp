class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int destination=n-1;
        int lastindex=0;
        int coverage=0;
        int jump=0;
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            coverage=max(coverage,i+nums[i]);
            if(i==lastindex){
                lastindex=coverage;
                jump++;
                 if(coverage>=destination){
                     return jump;
                }
            }           
        }
        return jump;        
    }
};