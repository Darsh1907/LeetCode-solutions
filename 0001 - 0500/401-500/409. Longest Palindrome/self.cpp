class Solution {
public:
    int longestPalindrome(std::string s) {
        int res = 0;
        unordered_map<char, int> umap; // frequency map
        for(int i = 0; i < s.size(); i++) umap[s[i]]++;
        for(auto i = umap.begin(); i != umap.end(); i++) {
            if((i->second) % 2 == 0) res += i->second;
            else res += (i->second - 1);
        }
        if(res == s.size()) return res;
        return res + 1;
    }
};