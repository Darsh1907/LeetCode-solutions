int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int p = 0;
    int q = 0;
    while(p<nums1Size && q<nums2Size){
        if(nums1[p]==nums2[q]) return nums1[p];
        else if(nums1[p]<nums2[q]) p++;
        else q++;
    }
    return -1;
}