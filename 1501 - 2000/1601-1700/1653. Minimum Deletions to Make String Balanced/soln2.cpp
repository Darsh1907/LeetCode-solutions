class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> deletions(n, 0);
        int count = 0;
        for(int i=0; i<n; i++) {
            deletions[i] += count;
            if(s[i]=='b') count++;
        }
        count = 0;
        for(int i=n-1; i>=0; i--) {
            deletions[i] += count;
            if(s[i]=='a') count++;
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++) ans = min(ans, deletions[i]);
        return ans;
    }
};