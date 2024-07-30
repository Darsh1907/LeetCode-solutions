#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>> &bridges) {
        vis[node] = true; // mark node as visited
        tin[node] = low[node] = timer; // initially set tin (time of insertion) and low (lowest time to reach) to timer
        timer++; // increment timer
        for(auto neigh : adj[node]) { // iterate over all neighbours
            if(neigh == parent) continue; // if neighbour is parent then skip
            if(!vis[neigh]) { // if neighbour is not visited then visit it
                dfs(neigh, node, vis, adj, tin, low, bridges); // visit neighbour
                low[node] = min(low[neigh], low[node]); // update low of node. low of node is minimum of low of neighbour and low of node
                if(low[neigh] > tin[node]) bridges.push_back({neigh, node}); // if low of neighbour is greater than tin of node then it is a bridge (you cant reach back to node from neighbour without this edge)
            }
            else low[node] = min(low[node], low[neigh]); // if neighbour is visited then update low of node to minimum of low of node and low of neighbour.
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        // creating adj
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        vector<int> tin(n); // time of insertion
        vector<int> low(n); // minimum tin from all adjacent nodes apart from parent (It shows the recheability of a node)
        vector<vector<int>> bridges; // to store bridges
        // start dfs
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};