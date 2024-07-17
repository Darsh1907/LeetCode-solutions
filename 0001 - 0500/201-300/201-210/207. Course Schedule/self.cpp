class Solution {
    // will check if there is a cycle
    bool dfs(int node, int parent, unordered_map<int, vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = true;
        pathVis[node] = true; // keeps track of visited nodes in current path. Path changes when DFS backtracks and selects another node.
        for(int adjNode: adj[node]) {
            if(!vis[adjNode] && dfs(adjNode, node, adj, vis, pathVis)) return true;
            else if(pathVis[adjNode]) return true;
        }
        pathVis[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // creating adj list
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<prerequisites.size(); i++) {
            int from_node = prerequisites[i][1];
            int to_node = prerequisites[i][0];
            adj[from_node].push_back(to_node);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        for(int i=0; i<numCourses; i++) {
            // If there is cycle, you cannot finish all courses. Therefore, return false.
            if(!vis[i] && dfs(i, -1, adj, vis, pathVis)) return false; 
        }
        return true;
    }
};