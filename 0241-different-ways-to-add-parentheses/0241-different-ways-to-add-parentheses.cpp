class Solution {
private:
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int x : left) {
                    for (int y : right) {
                        int temp = 0;
                        if (c == '+') {
                            temp = x + y;
                        }
                        else if (c == '-') {
                            temp = x - y;
                        }
                        else if (c == '*') {
                            temp = x * y;
                        }
                        res.push_back(temp);
                    }
                }
            }
        }
        // base case: expression is a number
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        memo[expression] = res;
        return res;
    }
};