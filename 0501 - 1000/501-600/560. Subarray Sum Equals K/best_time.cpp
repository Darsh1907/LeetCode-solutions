class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        vector<int> sums;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sums.push_back(sum);
        }
        unordered_map<int, int> counters;
        for (int i = 0; i < nums.size(); i++) {
            if (sums[i] == k) ++result;
            int q = sums[i] - k;
            auto ss = counters.find(q);
            if (ss != counters.end()) result += ss->second;
            auto s = counters.find(sums[i]);
            if (s == counters.end()) counters[sums[i]] = 1; 
            else ++counters[sums[i]];
        }
        return result;
    }
};