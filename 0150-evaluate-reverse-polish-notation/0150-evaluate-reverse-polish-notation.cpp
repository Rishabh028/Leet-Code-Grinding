class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for (auto & c : tokens) {
        if (c == "+" || c =="-" || c == "*" || c == "/") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            long long res = 0;

            if (c == "+") res = a + b;
            else if (c == "-") res = a - b;
            else if (c == "*") res = a * b;
            else res = a / b;
            st.push(res);
            }
            else {
                st.push(stoll(c));
            }
        }
        return st.top();
    }
};