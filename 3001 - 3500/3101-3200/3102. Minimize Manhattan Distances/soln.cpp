// References:
// https://www.youtube.com/watch?v=0yRcwMrawN0
// https://www.geeksforgeeks.org/maximum-manhattan-distance-between-a-distinct-pair-from-n-coordinates/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
private:
    // returns maxDist and index of points which result in maxDist excluding the 'excluded' point.
    vector<int> maxDist(vector<vector<int>>& points, int excluded){
        vector<int> res = {-1, -1, -1}; // {maxDist, i, j} - i and j are the points that gave maxDist
        // {index, corresponding_value} pairs
        pair<int, int> minSum={-1, INT_MAX};
        pair<int, int> maxSum={-1, INT_MIN};
        pair<int, int> minDiff={-1, INT_MAX};
        pair<int, int> maxDiff={-1, INT_MIN};
        for(int i=0; i<points.size(); i++){
            if(i==excluded) continue;
            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];
            if(sum < minSum.second) minSum={i, sum};
            if(sum > maxSum.second) maxSum={i, sum};
            if(diff < minDiff.second) minDiff = {i, diff};
            if(diff > maxDiff.second) maxDiff = {i, diff};
        }
        if((maxSum.second-minSum.second)>(maxDiff.second-minDiff.second)) {
            res[0] = maxSum.second - minSum.second;
            res[1] = minSum.first;
            res[2] = maxSum.first;
        }
        else {
            res[0] = maxDiff.second - minDiff.second;
            res[1] = minDiff.first;
            res[2] = maxDiff.first;
        }
        return res;
    }
public:
    int minimumDistance(vector<vector<int>>& points) {
        vector<int> v = maxDist(points, -1);
        int i = v[1];
        int j = v[2];
        return min(maxDist(points, i)[0], maxDist(points, j)[0]);
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    // Create a vector of vectors to represent the points
    vector<vector<int>> points = {{3, 10}, {5, 15}, {10, 2}, {4, 4}};
    // Call the minimumDistance function and store the result
    int result = solution.minimumDistance(points);
    // Print the result
    cout << "Minimum possible value for maximum distance between any two points by removing exactly one point: " << result << endl;
    return 0;
}