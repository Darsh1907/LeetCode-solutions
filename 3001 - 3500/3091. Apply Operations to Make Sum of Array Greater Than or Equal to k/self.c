int minOperations(int k) {
    if(k==1) return 0;
    int result = k;
    for(int i=2; i<=k; i++){
        int count = (i-1) + ceil(k*1.0/i)-1;
        if(count>result) break;
        else result = count;
    }
    return result;
}