class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        map<char,int> mp;
        for(auto a: s) mp[a]++;
        vector<pair<int,char>> arr;
        for(auto a: mp) arr.push_back({a.second,a.first});
        sort(arr.begin(), arr.end());
        int n = arr.size() - 1;
        while(n != -1) {
            while(arr[n].first) {
                result += arr[n].second;
                arr[n].first--;
            }
            n--;
        }
        return result;
    }
};