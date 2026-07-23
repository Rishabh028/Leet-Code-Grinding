class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n,i,a;
        n=nums.size();
        if(n<3)return n;
        else{
          a=1;
          while(a<=n){
            a=a*2;
          }
          return a;
        }
    }
};