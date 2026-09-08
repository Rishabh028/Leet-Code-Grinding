class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> frq;
        int cnt=0, stIdx=-1, minlen=INT_MAX ;
        if(s.size()<t.size()) return "";
        for(int i=0;i<t.size();i++) frq[t[i]]++;
        int l=0,r=0;
        while(r<s.size()){
            
            if(frq[s[r]]>0) cnt++;
            frq[s[r]]--;
            while(cnt == t.size()) {
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    stIdx = l;
                }
                frq[s[l]]++;
                if(frq[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? "" : s.substr(stIdx,minlen);
    }
};