class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
        return dp(word1, word2, m, n, cache);
    }

private:
    int dp(const string& word1, const string& word2, int i, int j, vector<vector<int>>& cache) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (cache[i][j] != -1) return cache[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            cache[i][j] = dp(word1, word2, i - 1, j - 1, cache);
        } else {
            cache[i][j] = 1 + min({
                dp(word1, word2, i - 1, j, cache),     
                dp(word1, word2, i, j - 1, cache),    
                dp(word1, word2, i - 1, j - 1, cache)  
            });
        }

        return cache[i][j];
    }
};