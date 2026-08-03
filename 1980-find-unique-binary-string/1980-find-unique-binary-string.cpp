class Solution {
public:
    string b(int r,int q){
        string t="";
        while(r!=0){
            int y=r%2;
            r=r/2;
            t=to_string(y)+t;
        }
        while(t.size()<q){
            t='0'+t;
        }
        return t;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int j=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++){
            string c=b(i,nums[0].size());
            if(j<nums.size()&&c==nums[j]){
                j++;
            }else{
                return c;
            }
        }
        return "";
    }
};
