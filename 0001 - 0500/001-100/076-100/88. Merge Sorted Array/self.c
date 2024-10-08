void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0, j = 0;
    int arr3[m + n];
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            arr3[i + j] = nums1[i];
            i++;
        } 
        else {
            arr3[i + j] = nums2[j];
            j++;
        }
    }
    while (i < m) {
        arr3[i + j] = nums1[i];
        i++;
    }
    while (j < n) {
        arr3[i + j] = nums2[j];
        j++;
    }
    for (int k = 0; k < m + n; k++) nums1[k] = arr3[k];
}