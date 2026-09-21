class Solution {
protected:
    int convolute(const vector<vector<int>>& A, const vector<vector<int>>& kernel, int xShift, int yShift) {
        int result = 0;
        for (int row = 0; row < A.size(); ++row) {
            for (int col = 0; col < A.size(); ++col) {
                result += A[row][col] * kernel[row + yShift][col + xShift];
            }
        }
        return result;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();

        vector<vector<int>> B_padded(3 * N-2, vector<int>(3 * N - 2, 0));

        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < N; ++col) {
                B_padded[row + N - 1][col + N - 1] = B[row][col];
            }
        }

        int maxOverlaps = 0;

        for (int xShift = 0; xShift < 2 * N - 1; ++xShift) {
            for (int yShift = 0; yShift < 2 * N - 1; ++yShift) {
                maxOverlaps = max(
                    maxOverlaps,
                    convolute(A, B_padded, xShift, yShift)
                );
            }
        }

        return maxOverlaps;
    }
};