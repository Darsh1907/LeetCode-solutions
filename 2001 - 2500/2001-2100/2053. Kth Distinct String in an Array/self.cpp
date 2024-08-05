class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, bool> umap; // string -> isDistinct
        for(int i=0; i<arr.size(); i++) {
            auto s = umap.find(arr[i]);
            if(s == umap.end()) umap[arr[i]] = true;
            else s->second = false;
        }
        int cnt=0;
        for(int i=0; i<arr.size(); i++) {
            auto s = umap.find(arr[i]);
            if(s->second) {
                cnt++;
                if(cnt==k) return s->first;
            }
        }
        return "";
    }
};