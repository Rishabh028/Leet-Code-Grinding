class Solution {
public:
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        stack<pair<int,int>> s;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int cnt = 0;
        for(int si = 0; si < n; si++)
        {
            for(int sj = 0; sj < m; sj++)
            {
                if(grid[si][sj] == '1' && !vis[si][sj])
                {
                    cnt++;
                    s.push({si, sj});
                    vis[si][sj] = true;
                    grid[si][sj] = '0';

                    while(!s.empty())
                    {
                        int i = s.top().first;
                        int j = s.top().second;
                        s.pop();
                        if(i-1 >= 0 && vis[i-1][j] != true && grid[i-1][j] == '1')
                        {
                            s.push({i-1,j});
                            vis[i-1][j] = true;
                            grid[i-1][j]='0';
                        }
                        if(j-1 >= 0 && vis[i][j-1] != true && grid[i][j-1] == '1')
                        {
                            s.push({i,j-1});
                            vis[i][j-1] = true;
                            grid[i][j-1]='0';
                        }
                        if(j+1 < m && vis[i][j+1] != true && grid[i][j+1] == '1')
                        {
                            s.push({i,j+1});
                            vis[i][j+1] = true;
                            grid[i][j+1]='0';
                        }
                        if(i+1 < n && vis[i+1][j] != true && grid[i+1][j] == '1')
                        {
                            s.push({i+1,j});
                            vis[i+1][j] = true;
                            grid[i+1][j]='0';
                        }
                    }
                }
            }
        }
        return cnt;
    }
};