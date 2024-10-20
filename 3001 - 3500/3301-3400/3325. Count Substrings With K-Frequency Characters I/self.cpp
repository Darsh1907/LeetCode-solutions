class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int l=0, r=0;
        int res = 0;
        unordered_map<char, int> umap;
        for(; r<n; r++) {
            umap[s[r]]++;
            while(umap[s[r]] >= k) {
                res += n-r;
                // shifting l
                umap[s[l]]--;
                l++;
            }
        }
        return res;
    }
};