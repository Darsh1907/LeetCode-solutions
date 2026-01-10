class Solution {
    // LEARNT FROM: https://www.youtube.com/redirect?event=comments&redir_token=QUFFLUhqa0hsc3JXNjhtSFVlTV8wY1lwRkdNVU9WZXU1d3xBQ3Jtc0tuc0doaDdYQ3F6QkNOUGEwN0VjSWl6SnNCTFNyZWJzLXMwU251WXRlaHZXZzJIZEdoZ0RwVUxjUmN4cC15b0hYbjM3ZkpWckZiTl80WlBxbmc4MUhQNkxXTnNTUmp3UkpuWjEyMk80bXA4bVh3MEZqQQ&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fminimum-ascii-delete-sum-for-two-strings%2Fsolutions%2F7482261%2Fbest-easiest-solution-beginner-friendly-xxa4m%2F
public:
    int solve(int i,int j,string& s1, string& s2,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size()){ // finished iterating both strings - return 0
            return 0;
        }
        // finished iterating one string - delete all other characters of the remainig string
        if(i==s1.size()){
            int ans =0;
            while(j<s2.size()){
                ans+=s2[j];
                j++;
            }
            return ans;
        }
        if(j==s2.size()){
            int ans =0;
            while(i<s1.size()){
                ans+=s1[i];
                i++;
            }
            return ans;
        }
        // if already calculated for this - return memoized response.
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // skip if both characters are same - no need to delete any character
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i+1,j+1,s1,s2,dp);
        } else{ // try deleting each character and take the one which is minimum.
            return dp[i][j]= min(solve(i+1,j,s1,s2,dp)+s1[i],solve(i,j+1,s1,s2,dp)+s2[j]);
        }
        return -1; // no need actually
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,s1,s2,dp);
    }
};