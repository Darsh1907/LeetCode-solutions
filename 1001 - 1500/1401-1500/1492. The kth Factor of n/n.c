int kthFactor(int n, int k) {
    if(k==1) return 1;
    int ans;
    for(int i=1; i<=n; i++){
        if(n%i == 0) {
            ans = i;
            k = k-1;
        } 
        if(k==0) return ans;
    }
    return -1;
}