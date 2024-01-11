class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a hash map
        unordered_map<int, int> m;
        for(int num: nums) {
            m[num]++;
        }

        // now we have a hash map of frequenceis so create a priority queue
        priority_queue<pair<int, int>> q;
        for(auto [key, val] : m) {
            q.push(pair(val, key));
        }

        // creating the result vector
        vector<int> ans;
        for(int i = 0 ; i < k ; i ++ ){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};