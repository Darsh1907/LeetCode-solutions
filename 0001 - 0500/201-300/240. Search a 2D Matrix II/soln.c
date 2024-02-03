bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize;
    int col = *matrixColSize;
    int rowIndex = 0;
    int colIndex = col-1;
    while(rowIndex < row && colIndex>=0 ) {
        int element = matrix[rowIndex][colIndex];
        if(element == target) return 1;
        if(element < target) rowIndex++;
        else colIndex--;
    }
    return 0;
}