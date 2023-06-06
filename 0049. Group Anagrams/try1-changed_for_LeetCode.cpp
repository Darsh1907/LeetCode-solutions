class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[256] = {0};
        int i;

        for(i=0; s[i]&&t[i]; i++){
            count[s[i]]++;
            count[t[i]]--;
        }

        // if(s[i] || t[i]) return false;

        for(i=0; i<256; i++)
            if(count[i]) return false;

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int strslen = strs.size();

        vector<vector<string>> result;
        vector<string> temp;
        vector<int> visited(strslen, 0);

        for(int i = 0; i < strslen; i++){
            if (!visited[i]){
                visited[i] = true;
                temp.clear();
                temp.push_back(strs[i]);
                for(int j = i + 1; j < strslen; j++){
                    if(!visited[j]){
                        if(strs[i].size()== strs[j].size())
                        if(isAnagram(strs[i], strs[j])){
                            visited[j] = true;
                            temp.push_back(strs[j]);
                        }
                    }
                }
                result.push_back(temp);
            }
        }

        return result;
    }
};