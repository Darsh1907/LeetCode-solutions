class Solution {
private:
    bool check(unordered_map<int, unordered_set<int>>& mp, int source, int destination, vector<int>& visited) {
        if(mp[source].find(destination) != mp[source].end() || source==destination) return true;
        visited[source] = 1;
        for(auto i=mp[source].begin(); i!=mp[source].end(); i++) {
            if(!visited[*i]) {
                if(check(mp, *i, destination, visited)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        if(edges.size()==0) return false;
        unordered_map<int, unordered_set<int>> mp;
        for(int i=0; i<edges.size(); i++) {
            mp[edges[i][0]].insert(edges[i][1]);
            mp[edges[i][1]].insert(edges[i][0]);
        }
        vector<int> visited(n, 0);
        return check(mp, source, destination, visited);
    }
};