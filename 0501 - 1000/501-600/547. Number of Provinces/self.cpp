class Solution {
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis) {
        if(vis[node]) return;
        vis[node] = true;
        for(int i=0; i<adj[node].size(); i++) if(adj[node][i]) dfs(adj, i, vis);
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                count++;
                dfs(isConnected, i, vis);
            }
        }
        return count;
    }
};
