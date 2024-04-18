// This method utilizes Depth-First Search (DFS) to traverse and count the perimeter of the island. 
// We define a helper function dfs(r, c) that recursively explores all adjacent cells of a given cell (r, c).

// If a cell is out of the grid bounds or is water (0), it contributes 1 to the perimeter (since water cells have an exposed border).
// If a cell is land (1), we mark it as visited by changing its value to -1 to avoid recounting, then recursively explore its four neighboring cells (up, down, left, right).
// The base case for the recursion is when the cell is out of bounds or is water, which contributes 1 to the perimeter.
// By iterating through each cell of the grid and invoking the dfs function on unvisited land cells, we can compute the total perimeter of the island.

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Base cases for DFS recursion
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0) {
            return 1; // Water contributes 1 to perimeter
        }
        if (grid[r][c] == -1) {
            return 0; // Already visited land cell
        }
        // Mark cell as visited
        grid[r][c] = -1;
        // Explore neighbors (up, down, left, right)
        return (dfs(grid, r + 1, c) +
                dfs(grid, r - 1, c) +
                dfs(grid, r, c + 1) +
                dfs(grid, r, c - 1));
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) perimeter += dfs(grid, r, c);
            }
        }
        return perimeter;
    }
};