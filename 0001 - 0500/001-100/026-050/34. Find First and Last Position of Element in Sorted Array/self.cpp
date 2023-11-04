class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]<target) s=mid+1; // Go to right
            else if(nums[mid]>target) e=mid-1; // Go to left
            else { // Go to left cuz need to find first occurence
                ans = mid;
                e = mid-1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]<target) s=mid+1; // Go to right
            else if(nums[mid]>target) e=mid-1; // Go to left
            else { // Go to right cuz need to find last occurence
                ans = mid;
                s=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
};