bool isPowerOfFour(int n){
    int i = 0;
    while(1){
        if(pow(4, i)==n) return true;
        if(pow(4, i)>n) return false;
        i++;
    }
}