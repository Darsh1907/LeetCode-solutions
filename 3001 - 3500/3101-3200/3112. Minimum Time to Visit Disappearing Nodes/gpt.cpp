class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w}); // Since the graph is undirected
        }
        vector<int> answer(n, -1); // Initialize answer array with -1
        // Priority queue to store nodes based on their tentative distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Initialize priority queue with node 0 and its distance 0
        pq.push({0, 0});
        // Dijkstra's algorithm
        while (!pq.empty()) {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            // If the node has already been visited, skip it
            if (answer[u] != -1) continue;
            // Update the answer for node u
            answer[u] = dist;
            // Check if node u disappears before we reach it
            if (dist >= disappear[u]) continue;
            // Explore neighbors of node u
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                // If node v hasn't been visited and it's not disappearing before reaching it
                if (answer[v] == -1 && dist + w < disappear[v]) {
                    pq.push({dist + w, v});
                }
            }
        }
        return answer;
    }
};