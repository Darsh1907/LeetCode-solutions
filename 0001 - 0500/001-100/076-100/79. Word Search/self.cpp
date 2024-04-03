class Solution {
private:
    bool solve(int i, int j, int word_index, vector<vector<char>>& board, string word) {
        if(word_index == word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(board[i][j] != word[word_index]) return false;
        char c = board[i][j];
        board[i][j]='\0';
        if(solve(i+1, j, word_index+1, board, word)) return true;
        else if(solve(i, j+1, word_index+1, board, word)) return true;
        else if(solve(i-1, j, word_index+1, board, word)) return true;
        else if(solve(i, j-1, word_index+1, board, word)) return true;
        board[i][j] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==word[0]) {
                    board[i][j] = '\0';
                    if(solve(i+1, j, 1, board, word)) return true;
                    else if(solve(i-1, j, 1, board, word)) return true;
                    else if(solve(i, j+1, 1, board, word)) return true;
                    else if(solve(i, j-1, 1, board, word)) return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};