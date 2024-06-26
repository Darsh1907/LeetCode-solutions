class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans; 
        for (int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end()) ans[mp[temp]].push_back(strs[i]); // get index for the already existing anagram and store the new word there.
            else {
                mp[temp] = ans.size(); // creating new index
                ans.push_back({strs[i]}); 
            }
        }
        return ans;
    }
};