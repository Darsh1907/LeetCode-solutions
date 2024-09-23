// This problem is very similar to 0/1 knapsack
// https://www.youtube.com/watch?v=_iGlRDLPLxM&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=128&t=5s

class Solution {
public:
    int solve(int i, int j, vector<int>& arr,int time, vector<vector<int>>&dp) {
        if(i==j) return 0;
        if(dp[i][time] != -1) return dp[i][time];
        dp[i][time] = max(arr[i]*time + solve(i+1, j, arr, time+1, dp), solve(i+1, j, arr, time, dp));
        return dp[i][time];
    }
    int maxSatisfaction(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        sort(arr.begin(),arr.end());
        return solve(0,n,arr,1,dp);
    }
};