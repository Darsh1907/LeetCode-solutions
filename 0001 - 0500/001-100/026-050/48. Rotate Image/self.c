void transpose(int** matrix, int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            // swap(matrix[i][j], matrix[j][i]);
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void swap_cols(int** matrix, int size){
    for(int i=0; i<size; i++){
        int l = 0;
        int r = size-1;
        while(l<r){
            // swap(matrix[i][l], matrix[i][r]);
            int temp = matrix[i][l];
            matrix[i][l] = matrix[i][r];
            matrix[i][r] = temp;
            l++;
            r--;
        }
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    transpose(matrix, matrixSize);
    swap_cols(matrix, matrixSize);
}