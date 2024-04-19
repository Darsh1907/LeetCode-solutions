void cover_island(char** grid, int gridSize, int gridColSize, int i, int j) {
    if(i<0 || i>=gridSize || j<0 || j>=gridColSize) return;
    if(grid[i][j]=='0') return;
    grid[i][j]='0';
    cover_island(grid, gridSize, gridColSize, i+1, j);
    cover_island(grid, gridSize, gridColSize, i-1, j);
    cover_island(grid, gridSize, gridColSize, i, j+1);
    cover_island(grid, gridSize, gridColSize, i, j-1);
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<*gridColSize; j++) {
            if(grid[i][j]=='1') {
                count++;
                cover_island(grid, gridSize, *gridColSize, i, j);
            }
        }
    }
    return count;
}