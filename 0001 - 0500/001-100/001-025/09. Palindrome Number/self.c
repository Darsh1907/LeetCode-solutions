bool isPalindrome(int x) {
    if(x<0) return false;
    int temp = x;
    long reversed = 0;
    while(temp){
        reversed = reversed*10 + temp%10;
        temp = temp/10;
    }
    return (x==reversed);
}