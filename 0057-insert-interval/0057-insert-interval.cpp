class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        int n=intervals.size();

        while(i<n && intervals[i][1]<newInterval[0]) {
            ans.push_back(intervals[i]); 
            i++;
        }

        int st=newInterval[0];
        int en=newInterval[1];
        while(i<n && intervals[i][0]<=en) {
            st=min(st,intervals[i][0]);
            en=max(en,intervals[i][1]); 
            i++;
        }
        ans.push_back({st,en});

        while(i<n) {
            ans.push_back(intervals[i]); 
            i++;
        }
        return ans;
    }
};