int smallestEvenMultiple(int n) {
    if(n%2==0) return n;
    if(n%2==1) return n*2;
    return 0; 
}