class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int i,g=s.size();
        for(i=0;i<g/2;i++)
        {
            char y=s[i];
            s[i]=s[g-i-1];
            s[g-i-1]=y;
        }
        
    }
};