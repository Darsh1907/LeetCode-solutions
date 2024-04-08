class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> s;
        int l=0, r=0;
        for(; r<k; r++) s.insert(nums[r]);
        vector<int> result;
        result.push_back(*(s.begin()));
        r--;
        while(r!=nums.size()-1) {
            r++;
            s.insert(nums[r]);
            s.erase(s.find(nums[l]));
            l++;
            result.push_back(*(s.begin()));
        }
        return result;
    }
};