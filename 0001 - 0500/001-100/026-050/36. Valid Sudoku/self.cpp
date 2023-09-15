class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check row
        set<char> s;
        for(int i=0; i<9; i++){
            s.clear();
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    if(s.find(board[i][j]) != s.end()) return false;
                    else s.insert(board[i][j]); 
                }
            }
        }
        // Check column
        for(int i=0; i<9; i++){
            s.clear();
            for(int j=0; j<9; j++){
                if(board[j][i]!='.'){
                    if(s.find(board[j][i]) != s.end()) return false;
                    else s.insert(board[j][i]);
                }
            }
        }
        // To check blocks
        int row=0;
        while(row<=8){
            // block 1 (first three columns)
            s.clear();
            for(int i=row; i<row+3; i++){
                for(int j=0; j<3; j++){
                    if(board[i][j]!='.'){
                        if(s.find(board[i][j]) != s.end()) return false;
                        else s.insert(board[i][j]);                    
                    }
                }
            }
            // block 2 (next three columns)
            s.clear();
            for(int i=row; i<row+3; i++){
                for(int j=3; j<6; j++){
                    if(board[i][j]!='.'){
                        if(s.find(board[i][j]) != s.end()) return false;
                        else s.insert(board[i][j]);                    
                    }
                }
            }
            // block 3 (last three columns)
            s.clear();
            for(int i=row; i<row+3; i++){
                for(int j=6; j<9; j++){
                    if(board[i][j]!='.'){
                        if(s.find(board[i][j]) != s.end()) return false;
                        else s.insert(board[i][j]);                    
                    }
                }
            }
            row = row+3; // To go to the next three rows
        }    
        return true;
    }
};