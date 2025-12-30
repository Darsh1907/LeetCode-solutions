class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // staircase method
        // basic intiuation: if grid[i][j] is -ve, every element to the right of it should also be -ve
        int rows = grid.size(), cols = grid[0].size();
        int row = rows-1, col = 0; // curr row, col to iterate
        int res = 0;
        while(row>=0 && col<cols) {
            if (grid[row][col] < 0) {
                res += cols - col;
                row--;
            } else col++;
        }
        return res;
    }
};