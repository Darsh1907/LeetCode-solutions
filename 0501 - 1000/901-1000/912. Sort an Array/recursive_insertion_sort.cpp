class Solution {
    void insertion_sort(vector<int>& arr, int i, int n) {
        // Base Case: i == n.
        if (i == n) return;
        int j = i;
        while (j>0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
        insertion_sort(arr, i+1, n);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        insertion_sort(nums, 0, n);
        return nums;
    }
};
