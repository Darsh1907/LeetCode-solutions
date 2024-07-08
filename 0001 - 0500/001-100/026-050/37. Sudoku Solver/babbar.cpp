class Solution {
    bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
        int n = board.size();
        for(int i=0; i<n; i++) {
            // row check
            if(board[row][i]==val) return false;
            // col check
            if(board[i][col]==val) return false;
            // 3*3 matrix check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false;
        }
        return true;
    }
    bool solve(vector<vector<int>>& board) {
        int n = board.size();
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                // check is cell is empty
                if(board[row][col]==0) {
                    for(int val=1; val<=9; val++) {
                        // check if some value is possible to insert
                        if(isSafe(row, col, board, val)) {
                            board[row][col] = val;
                            // recursive call
                            bool isPossibleAfterThis = solve(board);
                            if(isPossibleAfterThis) return true;
                            else board[row][col] = 0; // backtrack
                        }
                    }
                    return false;
                } 
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>> int_board(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') int_board[i][j] = 0;
                else int_board[i][j] = board[i][j] - '0';
            }
        }
        solve(int_board);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = int_board[i][j] + '0';
            }
        }
    }
};