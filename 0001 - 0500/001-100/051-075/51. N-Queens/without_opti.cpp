// Reference Video: https://www.youtube.com/watch?v=9wEwqNdOAVQ

class Solution {

    void addSolution(vector<vector<int>>& board, vector<vector<string>>& ans, int n) {
        vector<string> toAdd;
        for(int i=0; i<n; i++) {
            string temp;
            for(int j=0; j<n; j++) {
                if(board[i][j]) temp.push_back('Q');
                else temp.push_back('.');
            }
            toAdd.push_back(temp);
        }
        ans.push_back(toAdd);
    }

    bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
        // check only left side of row (because we fill only left to right)
        // Check left side of row
        for (int i=0; i<col; i++) {
            if (board[row][i]) return false;
        }

        // no need to check for column because of the structure of the code
        // (Once we place a queen in a column, we dont visit that column again while the queen is still placed)

        // Check upper diagonal on left side
        for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if (board[i][j]) return false;
        }

        // Check lower diagonal on left side
        for (int i=row, j=col; i<n && j>=0; i++, j--) {
            if (board[i][j]) return false;
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
        // base case
        if(col >= n) {
            addSolution(board, ans, n);
            return;
        }
        // solve
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 1; // place queen
                solve(col+1, ans, board, n);
                // backtrack
                board[row][col] = 0;
            }
        }
    }

public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};