// How much is change actually necessary while calculating the required path?
// How many extra edges do we need to add to the shortest path?
// NeetCode: https://www.youtube.com/watch?v=2F7gwxfy1CU

class Solution {
    void create_adj(vector<vector<int>>& adj, vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        return;
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        create_adj(adj, edges);
        queue<int> q;
        q.push(1);
        int curr_time = 0;
        int res = -1;
        vector<set<int>> check2(n+1); // a set for every node which shows how many times the node has been visited (by unique time values)
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int node = q.front();
                q.pop();
                if(node==n) {
                    if(res != -1) return curr_time;
                    res = curr_time;
                }
                for(auto neigh: adj[node]) {
                    if(check2[neigh].size()==0 || (check2[neigh].size()==1 && *check2[neigh].begin() != curr_time)) {
                        q.push(neigh);
                        check2[neigh].insert(curr_time);
                    }
                }
            }
            if((curr_time / change)%2 == 1) // if red light
                curr_time += change - (curr_time % change);
            curr_time += time;
        }
        return -1;
    }
};