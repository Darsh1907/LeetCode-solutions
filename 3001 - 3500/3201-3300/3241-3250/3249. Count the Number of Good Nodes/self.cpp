class Solution {
private:
    bool isLeaf(int node, int parent, vector<vector<int>>& adj) {
        for(int neigh: adj[node]) {
            if(neigh != parent) return false;
        }
        return true;
    }
    // DFS to calculate subtree sizes and count good nodes
    int dfs(int node, int parent, vector<vector<int>>& adj, int& goodNodes) {
        // base case
        if(isLeaf(node, parent, adj)) {
            goodNodes++;
            return 1;
        }
        vector<int> childSizes;
        int subtreeSize = 1; // Counting the current node
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {  // Avoid going back to the parent
                int childSubtreeSize = dfs(neighbor, node, adj, goodNodes);
                childSizes.push_back(childSubtreeSize);
                subtreeSize += childSubtreeSize;
            }
        }
        bool isGood = true;
        for(int size: childSizes) {
            if(size != childSizes[0]) {
                isGood = false;
                break;
            }
        }
        if(isGood) goodNodes++;
        // Curr node will return its subtree size
        return subtreeSize;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;  // Number of nodes
        vector<vector<int>> adj(n);
        // Create adj list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int goodNodes = 0;
        dfs(0, -1, adj, goodNodes);
        return goodNodes;
    }
};