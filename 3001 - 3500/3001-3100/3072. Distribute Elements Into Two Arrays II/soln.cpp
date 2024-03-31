class Solution {
public:
    int greaterCount(vector<int>& arr, int val) {
        return arr.end() - upper_bound(arr.begin(), arr.end(), val);
    }

    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1_sorted, arr2_sorted, arr1, arr2;
        arr1.push_back(nums[0]);
        arr1_sorted.push_back(nums[0]);
        arr2.push_back(nums[1]);
        arr2_sorted.push_back(nums[1]);
        for(int i = 2; i < n; i++) {
            int x = greaterCount(arr1_sorted, nums[i]);
            int y = greaterCount(arr2_sorted, nums[i]);
            if (x > y) {
                arr1_sorted.insert(arr1_sorted.end() - x , nums[i]);
                arr1.push_back(nums[i]);
            } 
            else if (x < y) {
                arr2_sorted.insert(arr2_sorted.end() - y, nums[i]);
                arr2.push_back(nums[i]);
            } 
            else {
                if(arr1.size() <= arr2.size()) {
                    arr1_sorted.insert(arr1_sorted.end() - x, nums[i]);
                    arr1.push_back(nums[i]);
                } 
                else {
                    arr2_sorted.insert(arr2_sorted.end() - y, nums[i]);
                    arr2.push_back(nums[i]);
                }
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};