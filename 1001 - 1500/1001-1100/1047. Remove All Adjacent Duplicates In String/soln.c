char* removeDuplicates(char* s) {
    char* ans = (char*)malloc(strlen(s) + 1);
    int ansIndex = 0;
    for (int i=0; s[i]!='\0'; i++) {
        if (ansIndex > 0) {
            if(ans[ansIndex - 1] == s[i]) ansIndex--;
            else ans[ansIndex++] = s[i];
        } 
        else ans[ansIndex++] = s[i];
    }
    ans[ansIndex] = '\0';
    return ans;
}