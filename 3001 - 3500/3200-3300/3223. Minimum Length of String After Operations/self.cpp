class Solution {
public:
    int minimumLength(string s) {
        int res;
        unordered_map<char, int> umap;
        for(int i=0; i<s.size(); i++) umap[s[i]]++;
        for(auto i=umap.begin(); i!=umap.end(); i++) {
            if(i->second > 2) {
                while(i->second >= 3) {
                    i->second -= 2;
                }
            }
            res += i->second;
        }
        return res;
    }
};