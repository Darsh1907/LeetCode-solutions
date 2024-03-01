char* maximumOddBinaryNumber(char* s){
    int one_count = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='1') one_count++;
        s[i]='0';
    }
    for(int i=0; one_count>1; i++){
        s[i]='1';
        one_count--;
    }
    s[strlen(s)-1] = '1';
    return s;
}