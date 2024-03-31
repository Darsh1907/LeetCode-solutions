vector<vector<int>> dp;
class Solution {
private:
    int solve(int i, int j, vector<int>& freq, int k){
        if(i==j || freq[j]-freq[i]<=k) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min(freq[i] + solve(i+1, j, freq, k), freq[j]-freq[i]-k + solve(i, j-1, freq, k));
    }
public:
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;
        vector<int> freq(26, 0);
        dp = vector<vector<int>> (26, vector<int>(26, -1));
        for(auto ch : word) freq[ch - 'a']++;
        sort(freq.begin(), freq.end());
        return solve(0, 25, freq, k);
    }
};