class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int rows, int cols) {
        if(rows*cols != original.size()) return {};
        vector<vector<int>> res(rows, vector<int>(cols));
        int itr = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                res[i][j] = original[itr++];
            }
        }
        return res;
    }
};