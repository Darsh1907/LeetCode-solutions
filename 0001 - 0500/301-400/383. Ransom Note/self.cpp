class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for(int i=0; i<magazine.size(); i++) umap[magazine[i]]++;
        for(int i=0; i<ransomNote.size(); i++) {
            if(umap.find(ransomNote[i]) == umap.end()) return false;
            else if(umap[ransomNote[i]] == 0) return false;
            else umap[ransomNote[i]]--;
        }
        return true;
    }
};