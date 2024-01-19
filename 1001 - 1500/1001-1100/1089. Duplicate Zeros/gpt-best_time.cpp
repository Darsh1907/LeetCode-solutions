class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Count the number of zeros in the original array
        for(int num : arr) if(num == 0) zeros++;

        int lastIndex = n + zeros - 1; // Calculate the index of the last element after duplication

        for (int i = n - 1; i >= 0; i--) {
            if(lastIndex < n) arr[lastIndex] = arr[i];
            if(arr[i] == 0) {
                lastIndex--;
                if(lastIndex < n) arr[lastIndex] = 0;
            }
            lastIndex--;
        }
    }
};