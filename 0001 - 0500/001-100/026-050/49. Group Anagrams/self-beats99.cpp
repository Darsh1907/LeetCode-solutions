class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(int i=0; i<strs.size(); i++) {
            string signature = strs[i];
            sort(signature.begin(), signature.end());
            umap[signature].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto i=umap.begin(); i!=umap.end(); i++) res.push_back(i->second);
        return res;
    }
};
