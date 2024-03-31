class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0]>=k) return 0;
        if(nums[1]>=k) return 1;
        int count = 0;
        int i0 = 0;
        int i1 = 1;
        while(i0<nums.size() && nums[i0]<k && i1<nums.size()) {
            unsigned long long int new_ele = nums[i0];
            new_ele = (new_ele<<1) + nums[i1];
            if(new_ele < k) nums.insert(upper_bound(nums.begin(), nums.end(), new_ele), new_ele);
            count++;
            i0 += 2;
            i1 += 2;
        }
        if(i0<nums.size() && nums[i0]<k) count++;
        return count;
    }
};