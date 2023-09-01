class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1<m && ptr2<n){
            if(nums2[ptr2]<nums1[ptr1]){
                result.push_back(nums2[ptr2]);
                ptr2++;
            }
            else{
                result.push_back(nums1[ptr1]);
                ptr1++;
            }
        }
        while(ptr1<m){
            result.push_back(nums1[ptr1]);
            ptr1++;
        }
        while(ptr2<n){
            result.push_back(nums2[ptr2]);
            ptr2++;            
        }
        nums1.clear();
        nums1 = result;
    }
};