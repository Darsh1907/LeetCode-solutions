void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize; // number of rows
    int n = *matrixColSize; // number of columns
    // for first row and first column
    bool zCol = false;
    bool zRow = false;
    if(matrix[0][0] == 0){
        zCol = true;
        zRow = true;
    }
    else {
        for(int i=0; i<n; i++){
            if(matrix[0][i] == 0){
                zRow = true;
                break;
            }
        }
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0){
                zCol = true;
                break;
            }
        }
    }
    // for rest all rows and columns, using first row and first columns as indicators
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // mark all zeros except first row and first column
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
        }
    }
    // for first row and column
    if(zRow){
        for(int i=0; i<n; i++) matrix[0][i] = 0;
    }
    if(zCol){
        for(int i=0; i<m; i++) matrix[i][0] = 0;
    }
}