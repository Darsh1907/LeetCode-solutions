class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]]++;
        vector<int> freq;
        for(auto i=mp.begin(); i!=mp.end(); i++) freq.push_back(i->second);
        sort(freq.begin(), freq.end());
        for(int i=0; i<freq.size(); i++) {
            if(k >= freq[i]) k -= freq[i];
            else return freq.size()-i;
        }
        return 0;
    }
};