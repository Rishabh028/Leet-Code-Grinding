class Solution {
public:
    int minOperations(string s) {
        int way1=0,way2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]!='0') way1++;
            }else{
                if(s[i]!='1') way1++;
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]!='1') way2++;
            }else{
                if(s[i]!='0') way2++;
            }
        }return min(way1,way2);
    }
};