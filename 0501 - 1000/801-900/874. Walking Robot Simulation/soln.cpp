class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for(auto& obstacle: obstacles) obs.insert(to_string(obstacle[0]) + "#" + to_string(obstacle[1]));
        // dir -> up=0, right=1, down=2, left=3
        int res=0, dir=0, x=0, y=0;
        vector<vector<int>> ds = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int command: commands) {
            if(command==-2) dir--;
            else if(command==-1) dir++;
            else {
                for(int i=0; i<command; i++) {
                    string pos = to_string(x+ds[dir][0]) + "#" + to_string(y+ds[dir][1]);
                    if(obs.find(pos) != obs.end()) break;
                    x += ds[dir][0];
                    y += ds[dir][1];
                }
                res = max(res, x*x+y*y);
            }
            if(dir==-1) dir=3;
            if(dir==4) dir=0;
        }
        return res;
    }
};