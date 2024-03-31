#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int sum=0, count=0, take_ind=0;
        while(take_ind<grid[0].size()){
            sum = 0;
            for(int i=0; i<grid.size() && sum<=k; i++){
                int temp = take_ind;
                while(temp>=0) sum += grid[i][temp--];
                if(sum<=k) count++;
            }
            take_ind++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 10;
    int result = solution.countSubmatrices(grid, k);
    cout << "The count of submatrices is: " << result << endl;
    return 0;
}