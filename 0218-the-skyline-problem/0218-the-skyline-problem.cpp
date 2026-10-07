class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<tuple<int, int, int>> events;

        for (auto &b : buildings) {
            events.push_back({b[0], -b[2], b[1]});
            events.push_back({b[1], b[2], b[1]});
        }

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>> pq;

        pq.push({0, INT_MAX});

        vector<vector<int>> ans;
        int prevHeight = 0;

        for (auto &[x, h, right] : events) {

            while (!pq.empty() && pq.top().second <= x) {
                pq.pop();
            }

            if (h < 0) {
                pq.push({-h, right});
            }

            while (!pq.empty() && pq.top().second <= x) {
                pq.pop();
            }

            int currHeight = pq.top().first;

            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};