 
class Solution {
public:
   
    bool isPalindrome(const string& str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

  
    void generate(int ind, vector<string>& cp, vector<vector<string>>& result, const string& s) {
        
        if (ind == s.length()) {
            result.push_back(cp);
            return;
        }

      
        for (int i = ind; i < s.length(); i++) {
            
            if (isPalindrome(s, ind, i)) {
                
                cp.push_back(s.substr(ind, i - ind + 1));
                
             
                generate(i + 1, cp, result, s);
                
                
                cp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cp;
        generate(0, cp, result, s);
        return result;
    }
};