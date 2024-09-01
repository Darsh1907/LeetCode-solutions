class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int curr = q.front();
            vis[curr] = true;
            q.pop();
            for(int key: rooms[curr]) {
                if(!vis[key]) q.push(key);
            }
        }
        for(bool check: vis) {
            if(!check) return false;
        }
        return true;
    }
};