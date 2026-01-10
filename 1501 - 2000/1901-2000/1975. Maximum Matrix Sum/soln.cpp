// REASONING:
// The operation flips two adjacent cells, so the parity of negative numbers is invariant.
// You can always rearrange signs (via paths of adjacent flips) except for that parity constraint.
// Therefore:
// If the number of negative elements is even, you can make all numbers positive.
// If it’s odd:
// If any zero exists, you can still make everything non-negative.
// Otherwise, one element must stay negative, and it should be the smallest absolute value element.

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCount = 0;
        bool hasZero = false;
        int minAbsNum = INT_MAX;
        long long totalAbsSum = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                minAbsNum = min(minAbsNum, abs(matrix[i][j]));
                totalAbsSum += abs(matrix[i][j]);
                if(matrix[i][j]<0) negCount++;
                else if(matrix[i][j]==0) hasZero = true; 
            }
        }
        if(negCount%2 == 0) return totalAbsSum;
        else {
            if(hasZero) return totalAbsSum;
            else return totalAbsSum - (2*minAbsNum);
        }
        return -1;
    }
};