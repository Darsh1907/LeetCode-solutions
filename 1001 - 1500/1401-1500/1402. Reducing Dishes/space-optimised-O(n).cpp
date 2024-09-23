class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        // vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int index=n-1; index>=0; index--) {
            for (int time = index; time >= 0; time--) {
                int inc = satisfaction[index] * (time + 1) + next[time + 1];
                int exc = 0 + next[time];
                curr[time] = max(inc, exc);
            }
            next = curr;
        }
        return next[0];
    }
};