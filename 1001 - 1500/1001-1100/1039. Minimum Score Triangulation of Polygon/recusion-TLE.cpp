class Solution {
private:
    int solve(vector<int>& v, int s, int e) {
        if(s+1 == e) return 0;
        int ans = INT_MAX;
        for(int i=s+1; i<e; i++) {
            ans = min(ans, v[s]*v[i]*v[e] + solve(v, s, i) + solve(v, i, e));
        }
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values, 0, n-1);
    }
};