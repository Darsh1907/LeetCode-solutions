class Solution {
public:
    void merge(vector<int>& result, vector<pair<int,int>>& nums_pair, int low, int mid, int high){
        int left = low; // left is the start of the first array
        int right = mid+1; // right is the start of the second array
        vector<pair<int,int>> temp; // temp will temporarily store the sorted combined array
        while(left<=mid && right<=high) {
            // If number from the second array is greater, just take it (Normal Process)
            if(nums_pair[left].first <= nums_pair[right].first){
                temp.push_back(nums_pair[right]);
                right++;
            }
            // If the number from first array is greater, it means it is also greater than high-right+1 elements (which btw also appear after the number in the actual input array)
            else {
                result[nums_pair[left].second] += (high-right+1);
                temp.push_back(nums_pair[left]);
                left++;
            }
        }
        for(; left<=mid; left++) temp.push_back(nums_pair[left]);
        for(; right<=high; right++) temp.push_back(nums_pair[right]);
        // Replace the elements with the sorted (required) elements of temp
        for(int i=low; i<=high; i++) nums_pair[i]=temp[i-low];
    }

    void mergesort(vector<int>& result, vector<pair<int,int>>& nums_pair, int low, int high) {
        // If low>=high (there is no array conceptually) then we return back
        if(low>=high) return;
        // Divide array conceptually using mid and apply merge sort on both the parts.
        int mid = (low + high)/2;
        mergesort(result, nums_pair, low, mid);
        mergesort(result, nums_pair, mid+1, high);
        // Merge the two sorted parts.
        merge(result, nums_pair, low, mid, high);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        // Create nums_pair which is just nums but with index values of each element.
        // This is so that the index values dont get lost in the merge sort process.
        // We will use indexes to update the result array
        vector<pair<int,int>> nums_pair(n);
        for(int i=0; i<n; i++) nums_pair[i] = {nums[i], i};
        // Initialize a result array which has the required output.
        vector<int> result(n);
        // Perform merge sort
        mergesort(result, nums_pair, 0, n-1);
        return result;
    }
};