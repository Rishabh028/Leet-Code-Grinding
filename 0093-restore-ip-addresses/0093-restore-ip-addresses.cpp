#include <vector>
#include <string>

class Solution {
private:
    void backtrack(const std::string& s, int start, std::vector<std::string>& path, std::vector<std::string>& result) {
        // Base Case: 4 valid segments that cover the full string
        if (path.size() == 4) {
            if (start == s.length()) {
                result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }

        // Try segments of length 1, 2, and 3
        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.length()) break;

            std::string segment = s.substr(start, len);

            // Leading zeros are invalid unless the segment is "0"
            if (segment.length() > 1 && segment[0] == '0') break;

            // Segment value must not exceed 255
            if (std::stoi(segment) > 255) break;

            path.push_back(segment);
            backtrack(s, start + len, path, result);
            path.pop_back(); // Backtrack
        }
    }

public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        std::vector<std::string> path;

        // Quick check: An IP address must have between 4 and 12 digits
        if (s.length() < 4 || s.length() > 12) return result;

        backtrack(s, 0, path, result);
        return result;
    }
};