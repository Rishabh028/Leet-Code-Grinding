class Solution {
public:
    int largestRectangleArea(vector<int> heights){
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        vector<int> nse(n);
        vector<int> pse(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            else{
                pse[i] = -1;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            else{
                nse[i] = n;
            }
            st.push(i);
        }

        for(int i=0; i<n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m);
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    v[j]++;
                }
                else{
                    v[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(v));
        }
        return maxArea;
    }
};