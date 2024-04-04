int maxDepth(char* s) {
    int count = 0;
    int result = 0;
    for(int i=0; i<strlen(s); i++) {
        if(s[i]=='(') count++;
        else if(s[i]==')') {
            if(count>result) result = count;
            count--;
        }
    }
    return result;
}