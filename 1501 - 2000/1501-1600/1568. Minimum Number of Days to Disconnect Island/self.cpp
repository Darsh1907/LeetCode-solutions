// Hint1: Return 0 if the grid is already disconnected.
// Hint2: Return 1 if changing a single land to water disconnect the island.
// Hint3: Otherwise return 2.
// Hint4: We can disconnect the grid within at most 2 days.

class Solution {
private:
    void cover_island(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j] = 0;
        cover_island(grid, i + 1, j);
        cover_island(grid, i - 1, j);
        cover_island(grid, i, j + 1);
        cover_island(grid, i, j - 1);
    }
    int numIslands(vector<vector<int>> grid) {
        int count = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    count++;
                    cover_island(grid, i, j);
                }
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int curr_islands = numIslands(grid);
        if(curr_islands>1 || curr_islands==0) return 0; // Already disconnected
        // Try removing each cell and check if it disconnects the island
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    // Temporarily set the cell to water
                    grid[i][j] = 0;
                    int islands_after_removal = numIslands(grid);
                    if(islands_after_removal>1 || islands_after_removal==0) return 1; // Disconnects the island with one removal
                    grid[i][j] = 1; // Restore the cell
                }
            }
        }
        return 2; // If no single removal works, return 2
    }
};