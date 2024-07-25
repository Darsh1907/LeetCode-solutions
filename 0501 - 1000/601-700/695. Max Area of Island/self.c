void cover_island(int** grid, int gridSize, int gridColSize, int i, int j, int* area) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize) return;
    if (grid[i][j] == 0) return;
    grid[i][j] = 0;
    (*area)++;
    cover_island(grid, gridSize, gridColSize, i+1, j, area);
    cover_island(grid, gridSize, gridColSize, i-1, j, area);
    cover_island(grid, gridSize, gridColSize, i, j+1, area);
    cover_island(grid, gridSize, gridColSize, i, j-1, area);
    return;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                int area = 0;
                cover_island(grid, gridSize, *gridColSize, i, j, &area);
                if (area > res) res = area;
            }
        }
    }
    return res;
}
