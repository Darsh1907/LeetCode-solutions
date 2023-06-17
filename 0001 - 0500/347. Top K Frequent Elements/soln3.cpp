class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int& n: nums) umap[n]++;

        priority_queue<pair<int, int>> pq;

        vector<int> res;
        for(auto& num: umap) {
            pq.push({num.second, num.first});
            if(pq.size() > umap.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }

        return res;
    }
};