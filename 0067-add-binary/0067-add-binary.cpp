class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            return addBinary(b, a);
        }
        
        int it_a = a.size() - 1;
        int it_b = b.size() - 1;
        int carry = 0;
        string ans = "";
        
        while (it_a >= 0) {
            if (a[it_a--] == '1') {
                carry++;
            }
            if (it_b >= 0 && b[it_b--] == '1') {
                carry++;
            }
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry == 1) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};