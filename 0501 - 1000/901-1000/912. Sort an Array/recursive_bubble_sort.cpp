class Solution {
    void bubble_sort(vector<int>& arr, int n) {
        // Base Case: range == 1.
        if (n==1) return;
        for (int j=0; j<=n-2; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        //Range reduced after recursion:
        bubble_sort(arr, n-1);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        bubble_sort(nums, n);
        return nums;
    }
};
