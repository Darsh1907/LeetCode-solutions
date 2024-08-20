// https://www.youtube.com/watch?v=oZ_xAIGCXw4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=122&pp=iAQB

class Solution {
    int solve(int n, vector<int>&days, vector<int>&costs, int index, vector<int>& dp) {
        // Base Case
        if(index>=n) return 0;
        // Check in DP
        if(dp[index] != -1) return dp[index];
        // 1 day pass
        int option1 = costs[0] + solve(n, days, costs, index+1, dp);
        // 7 days pass
        int i;
        for(i=index; i<n && days[i]<days[index]+7; i++);
        int option2 = costs[1] + solve(n, days, costs, i, dp);
        // 30 days pass
        for(i=index; i<n && days[i]<days[index]+30; i++);
        int option3 = costs[2] + solve(n, days, costs, i, dp);
        // return the min of options
        dp[index] = min(option1, min(option2, option3));
        return dp[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(n, days, costs, 0, dp);
    }
};