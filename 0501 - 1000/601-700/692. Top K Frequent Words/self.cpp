class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++) mp[words[i]]++;
        vector<pair<int, string>> stringFreqs;
        for(auto i=mp.begin(); i!=mp.end(); i++) stringFreqs.push_back({i->second, i->first});
        sort(stringFreqs.begin(), stringFreqs.end(), [](pair<int, string> a, pair<int, string>b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        vector<string> res;
        for(int i=0; i<k; i++) res.push_back(stringFreqs[i].second);
        return res;
    }
};
