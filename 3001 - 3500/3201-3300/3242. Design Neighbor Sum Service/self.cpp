// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator ()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class neighborSum {
public:
    unordered_map<int, int> row;    // Maps value to its row index
    unordered_map<int, int> col;    // Maps value to its column index
    unordered_map<pair<int, int>, int, pair_hash> ind; // Maps (row, col) to value
    int numRows, numCols;

    neighborSum(vector<vector<int>>& grid) {
        numRows = grid.size();
        numCols = grid[0].size();
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                int val = grid[i][j];
                row[val] = i;
                col[val] = j;
                ind[{i, j}] = val;
            }
        }
    }
    
    int adjacentSum(int value) {
        if (row.find(value) == row.end()) return 0;
        int r = row[value];
        int c = col[value];
        int sum = 0;
        if (r > 0) sum += ind[{r-1, c}];
        if (r < numRows-1) sum += ind[{r+1, c}];
        if (c > 0) sum += ind[{r, c-1}];
        if (c < numCols-1) sum += ind[{r, c+1}];
        return sum;
    }
    
    int diagonalSum(int value) {
        if (row.find(value) == row.end()) return 0;
        int r = row[value];
        int c = col[value];
        int sum = 0;
        if (r > 0 && c > 0) sum += ind[{r-1, c-1}];
        if (r < numRows-1 && c < numCols-1) sum += ind[{r+1, c+1}];
        if (r < numRows-1 && c > 0) sum += ind[{r+1, c-1}];
        if (r > 0 && c < numCols-1) sum += ind[{r-1, c+1}];
        return sum;
    }
};