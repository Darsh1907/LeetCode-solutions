class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int mid = total>>1; // Total/2
        vector<int> merged;
        // Push exactly mid+1 elements in the merged array (because we need only merged[mid] and merged[mid-1])
        int count = 0;
        int p = 0;
        int q = 0;
        while(count<(mid+1) && p<nums1.size() && q<nums2.size()){
            if(nums1[p]<nums2[q]){
                merged.push_back(nums1[p]);
                count++;
                p++;
            }
            else {
                merged.push_back(nums2[q]);
                count++;
                q++;
            }
        }
        while(count<(mid+1) && p<nums1.size()){
            merged.push_back(nums1[p]);
            p++;
            count++;
        }
        while(count<(mid+1) && q<nums2.size()){
            merged.push_back(nums2[q]);
            q++;
            count++;
        }
        if (total%2 == 1) return merged[mid];
        else return (merged[mid] + merged[mid - 1])/2.0;
    }
};