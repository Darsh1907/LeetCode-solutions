class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        int maxi = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(matrix[i][j] == '0') curr[j] = 0;
                else {
                    curr[j] = 1 + min({prev[j], curr[j+1], prev[j+1]});
                    maxi = max(maxi, curr[j]);
                }
            }
            swap(prev, curr);  // Move to the next row, make `prev` the `curr` row and reset `curr`
        }      
        return maxi * maxi;
    }
};