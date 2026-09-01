class Solution {
public:
    string simplifyPath(string path) {
        vector<string> p(1, "");
        int i = 0, n = path.size();
        while (i <= n) {
            if (i == n || path[i] == '/') {
                if (p.back() == ".") {
                    p.back() = "";
                }
                else if (p.back() == "..") {
                    p.pop_back();
                    if (p.size())
                        p.back() = "";
                    else
                        p.push_back("");
                }
                else if (p.back().size() > 0) 
                    p.push_back("");
            }
            else 
                p.back() += path[i];;
            ++i;
        }
        if (p[0] == "")
            return "/";
        string res;
        for (int i = 0; i < p.size() - 1; ++i)
            res += "/" + p[i];
        return res;
    }
};