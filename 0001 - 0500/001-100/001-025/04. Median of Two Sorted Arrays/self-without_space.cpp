class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int mid = total>>1; // total/2
        int mid_ele, pre_mid_ele;
        int count=0, p=0, q=0;
        while(count<=mid && p<nums1.size() && q<nums2.size()){
            if(nums1[p]<nums2[q]){
                if(count>=mid-1){
                    if(count==mid-1) pre_mid_ele = nums1[p];
                    else mid_ele = nums1[p];
                }
                count++;
                p++;
            }
            else {
                if(count>=mid-1){
                    if(count==mid-1) pre_mid_ele = nums2[q];
                    else mid_ele = nums2[q];
                }
                count++;
                q++;
            }
        }
        while(count<=mid && p<nums1.size()){
            if(count>=mid-1){
                if(count==mid-1) pre_mid_ele = nums1[p];
                else mid_ele = nums1[p];
            }
            count++;
            p++;
        }
        while(count<=mid && q<nums2.size()){
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