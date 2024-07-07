// Refere the LeetCode solution for N-Queens I

class Solution {
    inline bool isSafe(int row, int col, int n, vector<int>& left_row, vector<int>& lower_diagonal, vector<int>& upper_diagonal) {
        return left_row[row]==0 && lower_diagonal[row + col]==0 && upper_diagonal[n-1+col-row]==0;
    }
    void solve(int col, vector<string> &board, int &ans, vector<int> &left_row, vector<int> &lower_diagonal, vector<int> &upper_diagonal, int n) {
        if(col == n) {
            ans++;
            return;
        }
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, n, left_row, lower_diagonal, upper_diagonal)) {
                // Place Queen
                board[row][col] = 'Q';
                left_row[row] = 1;
                lower_diagonal[row + col] = 1;
                upper_diagonal[n - 1 + col - row] = 1;
                // Recursive Call
                solve(col + 1, board, ans, left_row, lower_diagonal, upper_diagonal, n);
                // Backtracking
                board[row][col] = '.';
                left_row[row] = 0;
                lower_diagonal[row + col] = 0;
                upper_diagonal[n - 1 + col - row] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        // Some hard codes
        if(n == 1) return 1;
        if(n <= 3) return 0;
        // initialise the answer vector and the board
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        // initialise the vectors
        vector<int> left_row(n, 0), lower_diagonal(2*n-1, 0), upper_diagonal(2*n-1, 0);
        // call the recursive function
        solve(0, board, ans, left_row, lower_diagonal, upper_diagonal, n);
        // return ans
        return ans;
    }
};