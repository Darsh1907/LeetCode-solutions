class Solution {
    void solve(vector<int>& candidates, int ind, int target, vector<int>& temp, vector<vector<int>>& res) {
        // Base case: if target is 0, add the current combination to the results
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        // Base case: if index is out of bounds or target becomes negative
        if(ind >= candidates.size() || target < 0) return;
        // Exclude the current index and move to the next index
        solve(candidates, ind + 1, target, temp, res);
        // Include the current index
        temp.push_back(candidates[ind]);
        // Since we can use the same index multiple times, we call solve with the same index
        solve(candidates, ind, target - candidates[ind], temp, res);
        // Backtrack to explore other combinations
        temp.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(candidates, 0, target, temp, res);
        return res;
    }
};