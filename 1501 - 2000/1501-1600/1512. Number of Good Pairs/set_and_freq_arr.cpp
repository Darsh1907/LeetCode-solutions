class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_set<int> num_set;
        int n = nums.size() ,c[101];
        for(int i = 0; i < n; i++) {
            if(num_set.find(nums[i]) == num_set.end()) {
                c[nums[i]] = 1;
                num_set.insert(nums[i]);
            }
            else c[nums[i]]++;
        }
        int sol = 0;
        for(auto &s : num_set) sol+=(c[s]*(c[s]-1))/2;
        return sol;
    }
};