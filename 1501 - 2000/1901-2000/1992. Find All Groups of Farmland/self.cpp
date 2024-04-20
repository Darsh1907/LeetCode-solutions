class Solution {
private:
    void cover_island(vector<vector<int>>& land, int gridSize, int gridColSize, int i, int j, vector<int>& rep) {
        if(i<0 || i>=gridSize || j<0 || j>=gridColSize) return;
        if(land[i][j]==0) return;

        if(i<rep[0]) rep[0]=i;
        else if(i>rep[2]) rep[2]=i;
        if(j<rep[1]) rep[1]=j;
        else if(j>rep[3]) rep[3]=j;

        land[i][j]=0;
        cover_island(land, gridSize, gridColSize, i+1, j, rep);
        cover_island(land, gridSize, gridColSize, i-1, j, rep);
        cover_island(land, gridSize, gridColSize, i, j+1, rep);
        cover_island(land, gridSize, gridColSize, i, j-1, rep);
        return;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int gridSize = land.size();
        int gridColSize = land[0].size();
        vector<vector<int>> result;
        for(int i=0; i<gridSize; i++) {
            for(int j=0; j<gridColSize; j++) {
                if(land[i][j]==1) {
                    vector<int> rep {i, j, i, j};
                    cover_island(land, gridSize, gridColSize, i, j, rep);
                    result.push_back(rep);
                }
            }
        }
        return result;
    }
};