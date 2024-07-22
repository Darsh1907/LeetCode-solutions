class Solution {
public:
    // Helper function to build the graph from the conditions
    vector<vector<int>> buildGraph(int& k, vector<vector<int>>& conditions) {
        vector<vector<int>> graph(k+1);
        for (auto& condition : conditions) {
            int pre = condition[0];
            int to = condition[1];
            graph[pre].push_back(to);
        }
        return graph;
    }

    // Function to perform topological sorting using BFS (Kahn's Algorithm)
    vector<int> getTopo(int& k, vector<vector<int>>& graph, vector<int>& inDeg) {
        vector<int> topoOrder;
        queue<int> q;
        for(int i=1; i<=k; i++) {
            if(inDeg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            for(int neighbor : graph[node]) {
                inDeg[neighbor]--;
                if(inDeg[neighbor] == 0) q.push(neighbor);
            }
        }
        if (topoOrder.size() != k) return {};  // Check for cycle
        return topoOrder;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Build graphs (adjacency lists)
        vector<vector<int>> rowGraph = buildGraph(k, rowConditions);
        vector<vector<int>> colGraph = buildGraph(k, colConditions);
        // indegree vectors. Will be used for Topological Ordering (in kanh's algo)
        vector<int> rowInDeg(k+1, 0);
        vector<int> colInDeg(k+1, 0);
        for(auto& condition : rowConditions) rowInDeg[condition[1]]++;
        for(auto& condition : colConditions) colInDeg[condition[1]]++;
        // Get topological orders for rows and columns
        vector<int> rowOrder = getTopo(k, rowGraph, rowInDeg);
        vector<int> colOrder = getTopo(k, colGraph, colInDeg);
        // If no valid topological sort, return an empty matrix
        if (rowOrder.empty() || colOrder.empty()) return {};
        // Map numbers to their column indices based on colOrder
        unordered_map<int, int> colIndex;
        for (int i=0; i<k; i++) colIndex[colOrder[i]] = i;
        // Build the result matrix
        vector<vector<int>> matrix(k, vector<int>(k));
        for (int i=0; i<k; i++) matrix[i][colIndex[rowOrder[i]]] = rowOrder[i];
        return matrix;
    }
};
