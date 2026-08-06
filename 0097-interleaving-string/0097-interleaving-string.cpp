class Solution {
public:
bool solve(vector<vector<int>> &dp , string &s1 , string &s2 , string &s3 , int i , int j , int k) {
    if(i == s1.size() && j == s2.size() && k == s3.size()) return true ;
     if(i == s1.size()) {
        while(j < s2.size()) {
            if(s2[j++] != s3[k++]) return false ;
        }
        return true ;
    }
     if(j == s2.size()) {
        while(i < s1.size()) {
            if(s1[i++] != s3[k++]) return false ;
        }
        return true ;
    }

    if(dp[i][j] != -1) return dp[i][j] ;
     
   bool take = false ;

    if(s2[j] == s3[k]) take |= solve(dp ,s1 , s2 , s3 , i , j + 1 , k + 1) ;
    if(s1[i] == s3[k]) take |= solve(dp , s1 , s2 , s3 , i + 1 , j , k + 1) ;
    
    return dp[i][j] = take ;
}

    bool isInterleave(string s1, string s2, string s3) {
    if(s1.size() + s2.size() != s3.size()) return false ;

    vector<vector<int>> dp(s1.size() , vector<int> (s2.size() , -1)) ;

    return solve(dp ,s1 , s2 , s3 , 0 , 0 , 0) ; 
    }
};