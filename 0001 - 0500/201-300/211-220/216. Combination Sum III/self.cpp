class Solution {
    void solve(vector<vector<int>>& res, vector<int>& temp, int k, int num, int n, int sum) {
        // Base Case: if sum equals n and we have exactly k numbers, add combination to result
        if (sum == n && temp.size() == k) {
            res.push_back(temp);
            return;
        }

        // Base Case: if sum exceeds target or number exceeds the limit
        if (sum > n || num > 9) return;

        // Include num
        temp.push_back(num);
        solve(res, temp, k, num + 1, n, sum + num);
        temp.pop_back(); // backtrack

        // Exclude num
        solve(res, temp, k, num + 1, n, sum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(res, temp, k, 1, n, 0);
        return res;
    }
};