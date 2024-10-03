class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]] = 0;
        int cnt = 1;
        for(auto i=mp.begin(); i!=mp.end(); i++) i->second = cnt++;
        vector<int> res;
        for(int num: arr) res.push_back(mp[num]);
        return res;
    }
};