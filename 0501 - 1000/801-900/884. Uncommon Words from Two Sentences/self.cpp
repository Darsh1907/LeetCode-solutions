class Solution {
private:
    // Function to process a string and populate the map
    void processString(const string& s, unordered_map<string, int>& umap) {
        string temp;
        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    umap[temp]++;
                    temp.clear();
                }
            } 
            else temp.push_back(c);
        }
        if(!temp.empty()) umap[temp]++;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> umap1;
        unordered_map<string, int> umap2;
        // Process both sentences and populate the maps
        processString(s1, umap1);
        processString(s2, umap2);
        // Collect uncommon words
        vector<string> res;
        for(const auto& entry : umap1) {
            if(entry.second == 1 && umap2.find(entry.first) == umap2.end()) {
                res.push_back(entry.first);
            }
        }
        for(const auto& entry : umap2) {
            if(entry.second == 1 && umap1.find(entry.first) == umap1.end()) {
                res.push_back(entry.first);
            }
        }
        return res;
    }
};