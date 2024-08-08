// Refer: https://www.youtube.com/watch?v=Xf5Zm5Y8PKM
class Solution {
    inline bool isValid(int rows, int cols, int rStart, int cStart) {
        return rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols;
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        res.push_back({rStart, cStart});
        int step = 1;  // Initial step size
        while (res.size() < rows * cols) {
            // Move right
            for (int i = 0; i < step; ++i) {
                cStart++;
                if (isValid(rows, cols, rStart, cStart)) res.push_back({rStart, cStart});
            }
            // Move down
            for (int i = 0; i < step; ++i) {
                rStart++;
                if (isValid(rows, cols, rStart, cStart)) res.push_back({rStart, cStart});
            }
            // Increment step size for next two directions
            step++;
            // Move left
            for (int i = 0; i < step; ++i) {
                cStart--;
                if (isValid(rows, cols, rStart, cStart)) res.push_back({rStart, cStart});
            }
            // Move up
            for (int i = 0; i < step; ++i) {
                rStart--;
                if (isValid(rows, cols, rStart, cStart)) res.push_back({rStart, cStart});
            }
            // Increment step size for next round
            step++;
        }        
        return res;
    }
};
