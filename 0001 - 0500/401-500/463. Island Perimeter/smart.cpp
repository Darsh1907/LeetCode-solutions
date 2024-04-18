// In this method, we iterate through each cell of the grid. 
// For every cell that represents land (denoted by 1), we initially assume it contributes 4 units to the perimeter. 
// Then, we adjust this count based on the neighboring cells.

// For each land cell (grid[r][c] == 1), add 4 to the perimeter count since the cell has four potential sides.
// Check the left neighbor (grid[r][c-1]) and the top neighbor (grid[r-1][c]). 
// If either of these neighbors is also land (1), it means the shared side between the current cell and its neighbor is internal to the island and should not contribute to the perimeter. 
// Therefore, we subtract 2 from the perimeter count for each such shared side.

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += 4;
                    if (r>0 && grid[r-1][c]==1) perimeter -= 2;
                    if (c>0 && grid[r][c-1]==1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};