class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int, int>> store(n);
        for(auto pi: pick) {
            int player = pi[0];
            int color = pi[1];
            store[player][color]++;
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            bool satisfies = false;
            for(auto itr=store[i].begin(); itr!=store[i].end(); itr++) {
                if(itr->second > i) satisfies = true;
                if(satisfies) break;
            }
            if(satisfies) count++;
        }
        return count;
    }
};