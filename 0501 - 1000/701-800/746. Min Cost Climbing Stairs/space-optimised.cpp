// As seen from the space-optimised solution, we only need to keep track of the last two elements of the dp array.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0], second = cost[1];
        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }
        return min(first, second);
    }
};