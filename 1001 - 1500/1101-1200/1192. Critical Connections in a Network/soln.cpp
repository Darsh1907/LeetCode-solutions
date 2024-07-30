// Use Tarjan's algorithm.

class Solution {
    int timer = 0;
    void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& res) {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for (auto neigh : adj[node]) {
            if (neigh == parent) continue;
            if (!vis[neigh]) {
                dfs(neigh, node, vis, adj, tin, low, res);
                low[node] = min(low[node], low[neigh]);
                // if the lowest number of steps needed to reach 'neigh' is more than the encounter time of 'node'
                if(low[neigh] > tin[node]) res.push_back({node, neigh});
            } 
            else low[node] = min(low[node], tin[neigh]);
        }
    }
    // Utility function to create adj
    void create_adj(vector<vector<int>>& adj, vector<vector<int>>& connections) {
        for (const auto& connection : connections) {
            int node1 = connection[0];
            int node2 = connection[1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        create_adj(adj, connections);
        vector<bool> vis(n, false); // visited array
        vector<int> tin(n, -1); // stores the time of insertion
        vector<int> low(n, -1); // lowest time of insertion apart from the parent
        vector<vector<int>> res;
        // Perform the DFS
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, -1, vis, adj, tin, low, res);
        }
        return res;
    }
};