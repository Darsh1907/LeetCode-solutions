class Solution {
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        if(q.empty()) return 0;
        int minutes = -1;
        while(!q.empty()) {
            minutes++;
            int n = q.size();
            for(int c=0; c<n; c++) {
                pair<int, int> top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;
                if((i-1 >= 0) && grid[i-1][j] == 1) {
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                }
                if((i+1 < grid.size()) && grid[i+1][j] == 1) {
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                }
                if((j-1 >= 0) && grid[i][j-1] == 1) {
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                }
                if((j+1 < grid[0].size()) && grid[i][j+1] == 1) {
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                }
            }
        }
        return minutes;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        int time = bfs(q, grid);
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                // if any fresh orange is left even after bfs traversals
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
