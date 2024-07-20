class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> maxOfCol(matrix[0].size(), INT_MIN);
        vector<int> minOfRow(matrix.size(), INT_MAX);
        // populate the maxOfCol and minOfRow
        for(int row=0; row<matrix.size(); row++) {
            for(int col=0; col<matrix[row].size(); col++) {
                int num = matrix[row][col];
                if(maxOfCol[col] < num) maxOfCol[col]=num;
                if(minOfRow[row] > num) minOfRow[row]=num;
            }
        }
        // Check every number with maxOfCol and maxOfRow
        vector<int> result;
        for(int row=0; row<matrix.size(); row++) {
            for(int col=0; col<matrix[0].size(); col++) {
                int num = matrix[row][col];
                if(num==maxOfCol[col] && num==minOfRow[row]) result.push_back(num);
            }
        }
        return result;
    }
};
