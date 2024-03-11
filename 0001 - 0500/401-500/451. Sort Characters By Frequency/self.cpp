class Solution {
public:
    string frequencySort(string s) {
        string result;
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++) mp[s[i]]++;
        vector<pair<int, char>> temp;
        for(auto i=mp.begin(); i!=mp.end(); i++) temp.push_back({i->second, i->first});
        sort(temp.begin(), temp.end());
        for(int i=temp.size()-1; i>=0; i--) result.append(temp[i].first, temp[i].second);
        return result;
    }
};