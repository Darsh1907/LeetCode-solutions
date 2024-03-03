class Solution {
public:
    int count = 0;

    void merge(vector<int>& nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        for(int i=left; i<=mid; i++){
            while(right<=high && nums[i] > 2*(long long)nums[right]){
                right++;
            }
            count += right-(mid+1);
        }
        left = low;
        right = mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        for(; left<=mid; left++) temp.push_back(nums[left]);
        for(; right<=high; right++) temp.push_back(nums[right]);
        for(int i=low; i<=high; i++) nums[i]=temp[i-low];
    }

    void mergesort(vector<int>& nums, int low, int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        mergesort(nums, low, mid);
        mergesort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return count;
    }
};