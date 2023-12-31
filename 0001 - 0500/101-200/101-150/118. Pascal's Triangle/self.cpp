#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        else if(numRows == 1) return {{1}};
        else if(numRows == 2) return {{1}, {1, 1}};
        else{
            vector<vector<int>> result = {{1}, {1, 1}};
            vector<int> temp;
            int temp2;
            for(int i=2; i<numRows; i++){
                temp.clear();
                temp.push_back(1);
                for(int j=0; j<(result[i-1].size()-1); j++){
                    temp2 = result[i-1][j] + result[i-1][j+1];
                    temp.push_back(temp2);
                }
                temp.push_back(1);
                result.push_back(temp);
            }
            return result;
        }
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