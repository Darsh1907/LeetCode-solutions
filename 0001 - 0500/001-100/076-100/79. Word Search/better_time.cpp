class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && solve(board, word, 0, i , j)) return true;
            }
        }
        return false;
    }
    bool solve(vector<vector<char>>& board, string& word, int word_index, int i, int j) {
        if (board[i][j] == word[word_index]) {
            if((word_index + 1) == word.size()) return true;
            char tmp = board[i][j];
            board[i][j] = '0';
            if (j>0 && board[i][j-1] != '0' && solve(board, word, word_index+1, i, j-1)) {
                return true;
            } 
            else if (j<board[0].size()-1 && board[i][j+1]!='0' && solve(board, word, word_index+1, i, j+1)) {
                return true;
            } 
            else if (i>0 && board[i-1][j]!='0' && solve(board, word, word_index+1, i-1, j)) {
                return true;
            } 
            else if (i < board.size() - 1 && board[i+1][j] != '0' && solve(board, word, word_index + 1, i + 1, j)) {
                return true;
            }
            board[i][j] = tmp;
        }
        return false;
    }
};