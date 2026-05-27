class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for(int k=0; k<n; k++) temp.push_back(grid[k][i]);
            for(int k=0; k<n; k++) {
                if(temp == grid[k]) res++;
            }
        }
        return res;
    }
};