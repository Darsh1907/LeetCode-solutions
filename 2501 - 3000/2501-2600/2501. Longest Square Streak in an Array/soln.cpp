class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int max = -1;
        set<int> numSet(nums.begin(), nums.end());
        vector<int> sortedNums(numSet.begin(), numSet.end());
        for(int num : sortedNums) {
            long long curr = num;
            int count = 0;
            while(numSet.count(curr)) {
                numSet.erase(curr);
                curr *= curr;
                count++;
            }
            max = std::max(max, count);
        }
        if(max > 1) return max;
        return -1;
    }
};