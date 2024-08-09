class Solution {
private:
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        vector<int> nums(9);
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) nums[i*3 + j] = grid[row + i][col + j];
        }
        sort(nums.begin(), nums.end());
        if(nums != vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}) return false;
        int magicSum = 15; // Sum of any row, column or diagonal in a 3x3 magic square
        // Check rows
        for (int i=0; i<3; i++) {
            if (grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != magicSum) return false;
        }
        // Check columns
        for (int j=0; j<3; j++) {
            if (grid[row][col+j] + grid[row+1][col+j] + grid[row+2][col+j] != magicSum) return false;
        }
        // Check diagonals
        if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != magicSum) return false;
        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != magicSum) return false;
        // return true if everything satisfies
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i=0; i<=rows-3; i++) {
            for (int j=0; j<=cols-3; j++) {
                if(isMagicSquare(grid, i, j)) count++;
            }
        }
        return count;
    }
};