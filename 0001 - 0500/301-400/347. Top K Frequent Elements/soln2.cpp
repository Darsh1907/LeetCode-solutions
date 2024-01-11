#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) m[nums[i]]++;
        
        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++) buckets[it->second].push_back(it->first);
        
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) break;
            if (!buckets[i].empty()) result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }
        return result;
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