class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>path;
        backtrack(nums,res,0,path);
        return res;
    }   
    void backtrack(vector<int>& nums,vector<vector<int>>& res,int i,vector<int>& path){
        
        res.push_back(path);
        
        for(int k = i;k < nums.size();k++){
            path.push_back(nums[k]);
            backtrack(nums,res,k + 1,path);
            path.pop_back();
        }
    } 
};