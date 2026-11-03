typedef long long ll;

class Solution {
public:
    vector<string> ans;
    void solve(int idx, string &s, int target, string temp, ll val, int last) {
        if(idx == s.length()) {
            if(val == target) ans.push_back(temp);
            return;
        }
        for(int i = idx; i < s.length(); ++i) {
            string part = s.substr(idx, i - idx + 1);
            if(part.length() > 1 && part[0] == '0') break;
            ll num = stoll(part);
            if(idx == 0) {
                solve(i + 1, s, target, part, num, num);
            }
            else {
                solve(i + 1, s, target, temp + "+" + part, val + num, num);
                solve(i + 1, s, target, temp + "-" + part, val - num, -num);
                solve(i + 1, s, target, temp + "*" + part, val - last + last * num, last * num);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(0, num, target, "", 0, 0);
        return ans;
    }
};