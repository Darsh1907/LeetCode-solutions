class Solution {
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adj, vector<int>& result) {
        if (visited[node] == 1) return true;  // Cycle detected
        if (visited[node] == 2) return false; // Already visited, no cycle
        visited[node] = 1; // Mark as visiting
        for (int neighbor : adj[node]) {
            if (dfs(neighbor, visited, adj, result)) return true; // Cycle detected
        }
        visited[node] = 2; // Mark as visited
        result.push_back(node); // Add to result in reverse order
        return false; // No cycle detected
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> result;
        // Build adjacency list
        for(auto& edge : prerequisites) adj[edge[1]].push_back(edge[0]); // pre[1] -> pre[0]
        vector<int> visited(numCourses, 0); // 0 = not visited, 1 = visiting, 2 = visited
        // Perform DFS on each course
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) { // If not visited
                if (dfs(i, visited, adj, result)) return {}; // Cycle detected, return empty vector
            }
        }
        reverse(result.begin(), result.end()); // Reverse to get the correct order
        return result;
    }
};
