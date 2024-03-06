int countDigits(int num) {
    int dup=num, ans=0;
    while(dup) {
        if(num % (dup % 10) == 0) ans++;
        dup /= 10;
    }
    return ans;
}