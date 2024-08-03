class Solution {
    // Function to calculate flips needed for a given row or column to be palindromic
    int minFlipsToPalindrome(vector<int> vec) {
        int len = vec.size();
        int flips = 0;
        for (int i=0; i<len/2; ++i) {
            if (vec[i] != vec[len-i-1]) flips++;
        }
        return flips;
    }
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowFlips = 0;
        for (int i=0; i<m; i++) rowFlips += minFlipsToPalindrome(grid[i]);
    
        int colFlips = 0;
        for (int j=0; j < n; ++j) {
            vector<int> col(m);
            for(int i=0; i<m; i++) col[i] = grid[i][j];
            colFlips += minFlipsToPalindrome(col);
        }
        return min(rowFlips, colFlips);
    }
};