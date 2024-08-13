class Solution {
    void solve(vector<int>& candidates, int ind, int target, vector<int>& temp, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        for(int i=ind; i<candidates.size(); i++) {
            if(i>ind && candidates[i]==candidates[i-1]) continue; // skip duplicates
            if(candidates[i] > target) break; // no point in continuing
            temp.push_back(candidates[i]);
            solve(candidates, i+1, target-candidates[i], temp, res); // i+1 to avoid using same element
            temp.pop_back(); // backtrack
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, temp, res);
        return res;
    }
};