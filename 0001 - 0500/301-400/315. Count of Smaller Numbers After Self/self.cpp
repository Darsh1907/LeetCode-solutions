// Almost similar to Count Inversionns
// Can refer to the video of Count Inversions Striver

class Solution {
public:
    void merge(vector<int>& result, vector<pair<int,int>>& nums_pair, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<pair<int,int>> temp;
        while(left<=mid && right<=high){
            if(nums_pair[left].first <= nums_pair[right].first){
                temp.push_back(nums_pair[right]);
                right++;
            }
            else {
                // this is the important part. Rest all is simple merge sort
                result[nums_pair[left].second] += (high-right+1);
                temp.push_back(nums_pair[left]);
                left++;
            }
        }
        for(; left<=mid; left++) temp.push_back(nums_pair[left]);
        for(; right<=high; right++) temp.push_back(nums_pair[right]);
        for(int i=low; i<=high; i++) nums_pair[i]=temp[i-low];
    }

    void mergesort(vector<int>& result, vector<pair<int,int>>& nums_pair, int low, int high) {
        if(low>=high) return;
        int mid = (low + high)/2;
        mergesort(result, nums_pair, low, mid);
        mergesort(result, nums_pair, mid+1, high);
        merge(result, nums_pair, low, mid, high);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> nums_pair(n);
        for(int i=0;i<n;i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            nums_pair[i] = p;
        }
        vector<int> result(n, 0);
        mergesort(result, nums_pair, 0, n-1);
        return result;
    }
};