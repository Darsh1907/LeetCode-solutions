class Solution {
public:
    struct node{
        int u;
        int time;
    };
    
    struct compare{
        bool operator()(const node &a, const node &b){
            return a.time > b.time; // min heap
        }
    };
    
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> graph[n];
        for(vector<int> edge : edges){
            int u=edge[0], v=edge[1], t=edge[2];
            graph[u].push_back({v,t});
            graph[v].push_back({u,t});
        }
        vector<int> minTime(n,INT_MAX);
        minTime[0]=0;
        priority_queue<node,vector<node>,compare> pq;
        struct node p={0,0};
        pq.push(p);
        vector<int> ans(n,-1);
        while(pq.size()>0){ 
            p=pq.top();
            pq.pop();
            int u = p.u, curTime = p.time;
			// modifying condition if(curTime >= disappear[u]) continue; to avoid TLE
            if(curTime >= disappear[u] || minTime[u]<curTime)) continue;
            if(ans[u] == -1 || ans[u] > curTime) ans[u] = curTime;
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i].first, time=graph[u][i].second;
                if(minTime[v] > curTime+time && curTime+time < disappear[v]){
                    minTime[v] = curTime+time;
                    p={v, minTime[v]};
                    pq.push(p);
                }
            }
        }
        return ans;
    }
};