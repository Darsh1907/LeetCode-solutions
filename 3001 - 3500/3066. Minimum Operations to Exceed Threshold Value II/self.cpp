class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        while(nums[0]<k && nums.size()>1) {
            unsigned long long int new_ele = nums[0];
            new_ele = new_ele * 2 + nums[1];
            nums.erase(nums.begin(), nums.begin()+2);
            if(new_ele < k) nums.insert(upper_bound(nums.begin(), nums.end(), new_ele), new_ele);
            count++;
        }
        if(nums.size()==1 && nums[0]<k) count++;
        return count;
    }
};