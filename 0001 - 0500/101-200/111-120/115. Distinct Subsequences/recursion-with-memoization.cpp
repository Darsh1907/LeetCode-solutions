class Solution {
    int solve(int i, int j, string &s, string &t, vector<vector<int>>& memo) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int notTake = solve(i+1, j, s, t, memo);
        int take = 0;
        if(s[i] == t[j]) take=solve(i+1, j+1, s, t, memo);
        
        return memo[i][j] = take + notTake;
    }
public:
    int numDistinct(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        vector<vector<int>> memo(sSize, vector<int>(tSize, -1));
        return solve(0, 0, s, t, memo);
    }
};