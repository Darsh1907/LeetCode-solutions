class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int size = nums.size(), i=0, j=0, maxLen=0;
        multiset<int> s;
        while(j<size) {
            s.insert(nums[j]);
            int diff = *s.rbegin() - *s.begin();
            while(diff>limit && i<j) {
                auto it = s.find(nums[i]);
                s.erase(it);
                i++;
                diff = *s.rbegin() - *s.begin();
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};