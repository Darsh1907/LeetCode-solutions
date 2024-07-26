// hint1: Use Floyd-Warshall's algorithm to compute any-point to any-point distances. (Or can also do Dijkstra from every node due to the weights are non-negative).
// hint2: For each city calculate the number of reachable cities within the threshold, then search for the optimal city.

// Floyd-Warshall's: Multi-source shortest path algorithm

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        // initialize dist matrix according to the edges
		for (auto edge : edges) {
			dist[edge[0]][edge[1]] = edge[2];
			dist[edge[1]][edge[0]] = edge[2];
		}
        // for self node distances, it is initialized to 0
		for(int i=0; i<n; i++) dist[i][i] = 0;
        // Aply Floyd-Warshall's ALgo
		for(int k=0; k<n; k++) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		int cntCity = n; // stores the minimum number of cities reachable within distanceThreshold
		int cityNo = -1; // the city which has the minimum cntCity
		for (int city=0; city<n; city++) {
			int cnt=0;
			for(int adjCity=0; adjCity<n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold) cnt++;
			}
			if(cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
    }
};