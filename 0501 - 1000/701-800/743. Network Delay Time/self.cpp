// Dijkstra's algorithm
class Solution {
    void create_adj(vector<vector<int>>& times, vector<vector<pair<int, int>>>& adj) {
        for(int i=0; i<times.size(); i++) {
            int from = times[i][0];
            int to = times[i][1];
            int weight = times[i][2];
            adj[from].push_back({to, weight});
        }
        return;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        create_adj(times, adj);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {weight_to_reach_dest, dest}
        // answer - dist array
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        // Dijkstra's Algorithm (like BFS)
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue; // Ignore outdated distance
            for(auto neigh: adj[node]) {
                int adjNode = neigh.first;
                int edgeWeight = neigh.second;
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        // find the max dist:
        int max_dist = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(dist[i] > max_dist) max_dist = dist[i];
        }
        if(max_dist == INT_MAX) return -1;  // there exists a node which was not reachable
        return max_dist;
    }
};