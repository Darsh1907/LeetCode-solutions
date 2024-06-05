class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> umap;
        for(int i=0; i<words[0].size(); i++) umap[words[0][i]]++;

        for(int i=1; i<words.size(); i++) {
            unordered_map<char, int> temp;
            for(int j=0; j<words[i].size(); j++) temp[words[i][j]]++;
            for(auto p=umap.begin(); p!=umap.end(); p++) 
                p->second = min(temp[p->first], p->second);
        }

        vector<string> result;
        string empty;
        for(auto i=umap.begin(); i!=umap.end(); i++){
            string toPush = empty.append(1, i->first);
            for(int j=0; j<(i->second); j++) result.push_back(toPush);
            empty = "";
        }
        return result;
    }
};