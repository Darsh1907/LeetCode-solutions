class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int l = 0; l < n; l++) {
            long long sum = 0;
            unordered_set<long long> seen;
            for(int r = l; r < n; r++) {
                sum += nums[r];
                seen.insert(nums[r]);
                if(seen.find(sum) != seen.end()) ans++;
            }
        }
        return ans;
    }
};