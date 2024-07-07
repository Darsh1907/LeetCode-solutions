class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int mid = total>>1; // total/2
        int mid_ele, pre_mid_ele;
        int count=0, p=0, q=0;
        // Add elements until any one of the array is exhausted
        while(count<=mid && p<nums1.size() && q<nums2.size()) {
            // Add the smaller element
            if(nums1[p]<nums2[q]) {
                // If we have reached the mid element
                if(count>=mid-1) {
                    if(count==mid-1) pre_mid_ele = nums1[p];
                    else mid_ele = nums1[p];
                }
                count++;
                p++;
            }
            else {
                // If we have reached the mid element
                if(count>=mid-1) {
                    if(count==mid-1) pre_mid_ele = nums2[q];
                    else mid_ele = nums2[q];
                }
                count++;
                q++;
            }
        }
        // Add remaining elements from nums1 (if exists)
        while(count<=mid && p<nums1.size()){
            // If we have reached the mid element
            if(count>=mid-1) {
                if(count==mid-1) pre_mid_ele = nums1[p];
                else mid_ele = nums1[p];
            }
            count++;
            p++;
        }
        // Add remaining elements from nums2 (if exists)
        while(count<=mid && q<nums2.size()){
            // If we have reached the mid element
            if(count>=mid-1){
                if(count==mid-1) pre_mid_ele = nums2[q];
                else mid_ele = nums2[q];
            }
            count++;
            q++;
        }
        if (total%2 == 1) return mid_ele;
        else return (pre_mid_ele + mid_ele)/ 2.0;
    }
};