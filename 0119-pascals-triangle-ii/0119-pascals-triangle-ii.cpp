class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex = rowIndex + 1;
        vector<int> ans;
        long int res = 1;
        ans.push_back(res);
        for (int i = 1; i < rowIndex; i++) {
            res = res * (rowIndex - i);
            res = res / i;
            ans.push_back(res);
        }
        return ans;
    }
};