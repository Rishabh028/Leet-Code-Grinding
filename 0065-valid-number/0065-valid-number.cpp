class Solution {
public:
    bool isNumber(string s) {
    bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        int i = 0;
        int n = s.length();

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }

        while (i < n) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
            } else if (c == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; 
                if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-')) {
                    i++;
                }
            } else {
                break; 
            }
            i++;
        }

        while (i < n && s[i] == ' ') {
            i++;
        }

        return seenDigit && i == n;
    }
};