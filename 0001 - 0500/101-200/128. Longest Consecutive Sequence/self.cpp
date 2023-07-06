class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        // autoip = unique(nums.begin(), nums.end());
        // nums.resize(distance(nums.begin(), ip));

        sort(nums.begin(), nums.end());

        int max = 1;
        int count = 1;
        for(int i=0; i<(nums.size()-1); i++){
            if(nums[i+1] == nums[i]+1) count++;
            else if(nums[i+1] == nums[i]);
            else {
                if(count>max) max = count;
                count = 1;
            }
        }
        if(count>max) max = count;
        return max;
    }
};