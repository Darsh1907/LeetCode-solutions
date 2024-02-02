class Solution {
public:
    void transpose(vector<vector<int>>& matrix, int size){
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void swap_cols(vector<vector<int>>& matrix, int size){
        for(int i=0; i<size; i++){
            int l = 0;
            int r = size-1;
            while(l<r){
                swap(matrix[i][l], matrix[i][r]);
                l++;
                r--;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        transpose(matrix, size);
        swap_cols(matrix, size);
    }
};