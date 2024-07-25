// Kruskal's Algo
// https://www.youtube.com/watch?v=aBxjDBC4M1U
// https://youtu.be/DMnDM_sxVig
// https://youtu.be/FYrl7iz9_ZU

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i=0; i<n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        int res = findUPar(parent[node]);
        parent[node] = res;
        return res;
    }

    // I am using unionBySize here
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int get_num_of_disjoint_networks() {
        unordered_set<int> s; 
        for(int i=0; i<parent.size(); i++) s.insert(findUPar(i));
        return s.size();
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        if(cables+1 < n) return -1;
        DisjointSet ds(n);
        for(auto cable: connections) {
            if(ds.findUPar(cable[0]) != ds.findUPar(cable[1])) 
                ds.unionBySize(cable[0], cable[1]);
        }
        int components = ds.get_num_of_disjoint_networks();
        return components-1;
    }
};