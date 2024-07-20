class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        // create adj list
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            int fromNode = prerequisites[i][1];
            int toNode = prerequisites[i][0];
            adj[fromNode].push_back(toNode);
        }
        // Get indegrees for each node
        vector<int> inDeg(numCourses, 0);
        for(int i = 0; i < adj.size(); i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                inDeg[adj[i][j]]++;
            }
        }
        // Push nodes with 0 indegree on the queue
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDeg[i] == 0) q.push(i);
        }
        // Perform BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0; i<adj[node].size(); i++) {
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]] == 0) q.push(adj[node][i]);
            }
        }
        // If all courses are not included, there's a cycle
        if(ans.size() != numCourses) return {};
        return ans;
    }
};
