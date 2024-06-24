int min(int a, int b) {if(a<b) return a; return b;}
int max(int a, int b) {if(a>b) return a; return b;}

int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int mini = INT_MAX;
    int minj = INT_MAX;
    int maxi = INT_MIN;
    int maxj = INT_MIN;
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<*gridColSize; j++) {
            if(grid[i][j] == 1) {
                mini = min(mini, i);
                minj = min(minj, j);
                maxi = max(maxi, i);
                maxj = max(maxj, j);
            }
        }
    }
    return (maxi - mini + 1) * (maxj - minj + 1);
}