class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> rs;
        std::string s;
        GenParens(n, rs, s);
        return rs;
    }
    
private:
    void GenParens(const int n,
                   std::vector<std::string>& rs,
                   std::string& current,
                   int open = 0,
                   int closed = 0) {
        if (open == n && closed == n) {
            rs.push_back(current);
            return;
        }
        
        if (open < n) {
            current += '(';
            GenParens(n, rs, current, open + 1, closed);
            current.pop_back();
        }
        
        if (closed < open) {
            current += ')';
            GenParens(n, rs, current, open, closed + 1);
            current.pop_back();
        }
    }
};
