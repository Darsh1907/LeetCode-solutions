class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> umap;
        for(int num: arr) umap[num]++;
        for(int num: target) umap[num]--;
        for(auto i=umap.begin(); i!=umap.end(); i++) {
            if(i->second != 0) return false;
        }
        return true;
    }
};