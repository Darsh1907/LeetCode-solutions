bool isPalindrome(int x) {
    char str[20];
    sprintf(str, "%d", x);
    int start = 0;
    int end = strlen(str)-1;
    while(start < end){
        if(str[start] != str[end]) return false;
        start++;
        end--;
    }
    return true;
}