int sumOfTheDigitsOfHarshadNumber(int x) {
    int dup = x;
    int sum = 0;
    while(dup){
        sum = sum + dup%10;
        dup = dup/10;
    }
    if(x%sum==0) return sum;
    return -1;
}