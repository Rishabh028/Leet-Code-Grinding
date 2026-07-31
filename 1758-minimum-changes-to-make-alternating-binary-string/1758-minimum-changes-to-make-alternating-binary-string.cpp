class Solution {
public:
    int minOperations(string s) 
    {
        int a = 0, b = 0;
        int check = '0';
        for(int i = 0; i<s.size(); ++i) //start on 0
        {
            if(s[i] != check) a++;
            if(check == '0') check = '1';
            else check = '0';
        }
        check = '1';
        for(int i = 0; i<s.size(); ++i) //start on 1
        {
            if(s[i] != check) b++;
            if(check == '0') check = '1';
            else check = '0';
        }

        return min(a,b);
    }
};