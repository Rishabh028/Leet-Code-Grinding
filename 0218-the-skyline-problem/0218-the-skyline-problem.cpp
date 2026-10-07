class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq; 
        int i = 0, n = buildings.size();

        while (i < n || !pq.empty()) {
            int x;
            if (pq.empty() || (i < n && buildings[i][0] <= pq.top().second)) {
                x = buildings[i][0];        
            } else {
                x = pq.top().second;       
            }

            while (i < n && buildings[i][0] == x) {
                pq.push({buildings[i][2], buildings[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second <= x) pq.pop(); 

            int h = pq.empty() ? 0 : pq.top().first;
            if (res.empty() || res.back()[1] != h) res.push_back({x, h});
        }
        return res;
    }
};