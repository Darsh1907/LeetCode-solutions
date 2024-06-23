class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1) return 1;
        if(nums.size()==2){
            if(nums[0]==nums[1]) return 1;
            return 2;
        }
        int min_index = 0;
        int max_index = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[min_index]) min_index = i;
            else if(nums[i]>nums[max_index]) max_index = i;
        }
        min_index++;
        max_index++;
        int dist_from_left = min(min_index, max_index);
        int dist_from_right = nums.size() - max(min_index, max_index) + 1;
        int result = 0;
        if(dist_from_left <= dist_from_right) {
            result = dist_from_left;
            dist_from_left = max(min_index, max_index) - dist_from_left;
        }
        else {
            result = dist_from_right;
            dist_from_right = nums.size() - min(min_index, max_index) + 1 - dist_from_right;
        }
        result = result + min(dist_from_left, dist_from_right);
        return result;
    }
};