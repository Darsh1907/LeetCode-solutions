int max(int a, int b){
    if(a>b) return a;
    return b;
}

int maximumLengthSubstring(char* s) {
    int freq[28] = {0};
    int s_size = strlen(s);
    int result=0;
    int l=0, r=0;
    while(r<s_size) {
        if(++freq[s[r]-'a'] > 2) {
            while(freq[s[r]-'a'] > 2){
                freq[s[l]-'a']--;
                l++;
            }
        }
        result = max(r-l+1, result);
        r++;
    }
    return result;
}