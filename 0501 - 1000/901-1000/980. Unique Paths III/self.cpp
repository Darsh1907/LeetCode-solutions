#include<vector>
#include<utility>
using namespace std;

class Solution {
    void solve(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited, int& ans, pair<int, int>& end, int remain) {
        // check whether visited
        if (visited[row][col]) return;
        // check whether an obstacle is there at that place
        if (grid[row][col] == -1) return;
        // check if you reached the destination after covering All non-obstacle cells
        if (row==end.first && col==end.second && remain==1) {
            ans++;
            return;
        }
        // mark current node as visited and update remaining
        visited[row][col] = true;
        remain--;
        // explore whichever directions are possible to go
        if ((col - 1) >= 0) solve(grid, row, col - 1, visited, ans, end, remain);
        if ((col + 1) < grid[0].size()) solve(grid, row, col + 1, visited, ans, end, remain);
        if ((row - 1) >= 0) solve(grid, row - 1, col, visited, ans, end, remain);
        if ((row + 1) < grid.size()) solve(grid, row + 1, col, visited, ans, end, remain);
        // BackTrack
        visited[row][col] = false;
        remain++;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        int remain = 0;
        // get start and end positions
        pair<int, int> start, end;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) start = {i, j};
                else if (grid[i][j] == 2) end = {i, j};
                if (grid[i][j] != -1) remain++; // Count all non-obstacle cells
            }
        }
        // Call the recursive function
        solve(grid, start.first, start.second, visited, ans, end, remain);
        // Return ans
        return ans;
    }
};