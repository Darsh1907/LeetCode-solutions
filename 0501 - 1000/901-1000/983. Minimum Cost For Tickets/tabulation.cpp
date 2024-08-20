// https://www.youtube.com/watch?v=oZ_xAIGCXw4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=122&pp=iAQB

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        // Traverse from the end to the start of days
        for(int index=n-1; index>=0; index--) {
            // 1 day pass
            int option1 = costs[0] + dp[index+1];
            // 7 day pass
            int i;
            for(i=index; i<n && days[i] < days[index] + 7; i++);
            int option2 = costs[1] + dp[i];
            // 30 day pass
            for(i=index; i<n && days[i] < days[index] + 30; i++);
            int option3 = costs[2] + dp[i];
            // Minimum cost at index
            dp[index] = min(option1, min(option2, option3));
        }
        return dp[0];
    }
};