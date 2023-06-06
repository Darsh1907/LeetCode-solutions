#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Write your code here.
    }
};

int main() {
    Solution solution;

    // Test your implementation
    int numRows = 5;
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