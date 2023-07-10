#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;

        for (int i=0; i<numRows; i++) {
            vector<int> temp(i+1, 1);
            for(int j=1; j<i; j++){
                temp[j] = output[i-1][j] + output[i-1][j-1];
            }
            output.push_back(temp);
        }
        return output;
    }
};

int main() {
    Solution solution;
    // Test your implementation
    int numRows = 7;
    vector<vector<int>> result = solution.generate(numRows);
    // Print the result
    for (const auto& row : result) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}