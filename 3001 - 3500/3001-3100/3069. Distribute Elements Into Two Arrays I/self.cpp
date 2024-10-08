class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1(nums.size());
        arr1[0]=nums[0];
        int k = 1; // Next empty position of arr1
        vector<int> arr2;
        arr2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
            if(arr1[k-1] > arr2[arr2.size()-1]) arr1[k++] = nums[i];
            else arr2.push_back(nums[i]);
        }
        for(int i=0; i<arr2.size(); i++) arr1[k++] = arr2[i];
        return arr1;
    }
};