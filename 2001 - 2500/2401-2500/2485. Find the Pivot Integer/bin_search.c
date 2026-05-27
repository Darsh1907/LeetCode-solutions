int pivotInteger(int n) {
    int s = 1;
    int e = n;
    while(s<=e){
        int mid = (s+e)/2;
        int left_sum = mid*(mid+1)/2;
        int right_sum = n*(n+1)/2 - left_sum + mid;
        if(left_sum == right_sum) return mid;
        if(left_sum > right_sum) e=mid-1;
        else s=mid+1;
    }
    return -1;
}