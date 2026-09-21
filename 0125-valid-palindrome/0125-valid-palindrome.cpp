class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        int n = filtered.size() - 1;
        int l = 0;
        int r = n;

        while (l < r) {
            if (filtered[l] != filtered[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};