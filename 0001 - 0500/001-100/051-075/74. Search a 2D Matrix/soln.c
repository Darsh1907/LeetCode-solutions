bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rows = matrixSize;
    int cols = *matrixColSize;

    int start = 0;
    int end = rows*cols - 1;
    int mid = start + (end-start)/2;

    while(start<=end){
        int element = matrix[mid/cols][mid%cols];
        if(element==target) return 1;
        if(element<target) start=mid+1;
        else end = mid-1;
        mid = start + (end-start)/2;
    }
    return 0;
}