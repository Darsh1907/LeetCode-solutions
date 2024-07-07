// Reference: https://www.youtube.com/watch?v=9wEwqNdOAVQ

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

    bool isSafe(int row, int col, unordered_map<int, bool>& RowMap, unordered_map<int, bool>& BottomDiaMap, unordered_map<int, bool>& TopDiaMap, int n) {
        // check only left side of row (because we fill only left to right)
        // Check left side of row
        auto rowCheck = RowMap.find(row);
        if(rowCheck==RowMap.end());
        else if(rowCheck->second==true) return false;

        // no need to check for column because of the structure of the code
        // (Once we place a queen in a column, we dont visit that same column again while the queen is still placed)

        // Check upper diagonal on left side
        auto topDiaCheck = TopDiaMap.find(n+col-row-1);
        if(topDiaCheck==TopDiaMap.end());
        else if(topDiaCheck->second==true) return false;

        // Check lower diagonal on left side
        auto bottomDiaCheck = BottomDiaMap.find(row+col);
        if(bottomDiaCheck == BottomDiaMap.end());
        else if(bottomDiaCheck->second==true) return false;

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<vector<int>>& board, unordered_map<int, bool>& RowMap, unordered_map<int, bool>& BottomDiaMap, unordered_map<int, bool>& TopDiaMap, int n) {
        // base case
        if(col >= n) {
            addSolution(board, ans, n);
            return;
        }
        // solve
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, RowMap, BottomDiaMap, TopDiaMap, n)) {
                // place queen
                board[row][col] = 1;
                RowMap[row] = true;
                BottomDiaMap[row+col] = true;
                TopDiaMap[n+col-row-1] = true;
                // place for next column
                solve(col+1, ans, board, RowMap, BottomDiaMap, TopDiaMap, n);
                // backtrack
                board[row][col] = 0;
                RowMap[row] = false;
                BottomDiaMap[row+col] = false;
                TopDiaMap[n+col-row-1] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int> (n, 0));
        unordered_map<int, bool> RowMap; // row -> (hasQueen?)
        unordered_map<int, bool> BottomDiaMap; // (row+col) -> (hasQueen?)
        unordered_map<int, bool> TopDiaMap; // (n+col-row-1) -> (hasQueen?)
        vector<vector<string>> ans;
        solve(0, ans, board, RowMap, BottomDiaMap, TopDiaMap, n);
        return ans;
    }
};