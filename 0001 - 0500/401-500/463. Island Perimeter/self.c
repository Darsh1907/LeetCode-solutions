int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int peri = 0;
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<*gridColSize; j++) {
            if(grid[i][j]==1) {
                if(i==0 || grid[i-1][j]==0) peri++;
                if(i==gridSize-1 || grid[i+1][j]==0) peri++;
                if(j==0 || grid[i][j-1]==0) peri++;
                if(j==*gridColSize-1 || grid[i][j+1]==0) peri++;
            }
        }
    }
    return peri;
}