class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++) umap[nums[i]]++;
        vector<pair<int, int>> toSort;
        for(auto i=umap.begin(); i!=umap.end(); i++) toSort.push_back({i->second, i->first});
        sort(toSort.begin(), toSort.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.first==b.first) return a.second > b.second;
            return a.first < b.first;
        });
        vector<int> res;
        for(int i=0; i<toSort.size(); i++) {
            int num = toSort[i].second;
            int times = toSort[i].first;
            for(int i=0; i<times; i++) res.push_back(num);
        }
        return res;
    }
};
