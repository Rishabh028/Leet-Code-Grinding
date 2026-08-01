class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 0; i<s.length(); i++){
            if (s[i] == '0' and s[i+1] == '1'){
                return false;
            }
        }
        return true;
    }
};