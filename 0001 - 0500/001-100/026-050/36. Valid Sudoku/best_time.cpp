class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0;i<n;i++){
            vector<int> seenVert(n,0);
            vector<int> seenHor(n,0);
            vector<int> seenBox(n,0);
            for(int j = 0;j<n;j++){
                if(board[i][j] != '.'){
                    if(seenVert[board[i][j]-'1']) return false;
                    seenVert[board[i][j]-'1'] = 1;
                }
                if(board[j][i] != '.'){
                    if(seenHor[board[j][i]-'1']) return false;
                    seenHor[board[j][i]-'1'] = 1;
                }
                if(board[(3*(i/3))+(j/3)][(3*(i%3))+(j%3)] != '.'){
                    if(seenBox[board[(3*(i/3))+(j/3)][(3*(i%3))+(j%3)]-'1']) return false;
                    seenBox[board[(3*(i/3))+(j/3)][(3*(i%3))+(j%3)]-'1'] = 1;
                }
            }
        }
        return true;
    }
};