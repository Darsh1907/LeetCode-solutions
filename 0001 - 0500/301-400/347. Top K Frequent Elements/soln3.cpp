#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

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

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> result = solution.topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
