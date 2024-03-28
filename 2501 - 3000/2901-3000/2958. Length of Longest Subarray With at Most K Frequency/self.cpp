class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count=0, l=0, r=0;
        while(r<nums.size()){
            freq[nums[r]]++;
            while(freq[nums[r]]>k && l<r) {
                freq[nums[l++]]--;
            }
            r++;
            count = max(count, (r-l));
        }
        return count;
    }
};