// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int res = n;
    int s = 1;
    int e = n;
    int mid;
    while(s<=e) {
        mid = s + (e-s)/2;
        if(isBadVersion(mid)) {
            e = mid-1;
            res = mid; 
        }
        else s = mid+1;
    }
    return res;
}