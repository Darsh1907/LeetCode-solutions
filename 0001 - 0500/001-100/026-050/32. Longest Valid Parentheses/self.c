int max(int* a, int* b){
    if(a>=b) return a;
    return b;
}

void left_pass(char* s, int n) {
    int open=0, close=0;
    for(int i=0; i<n; i++){
        if(s[i]=='(') open++;
        else {
            close++;
            if(close > open) {
                s[i] = '*';
                close--;
            }
        }
    }
}

void right_pass(char* s, int n) {
    int open=0, close=0;
    for(int i=n-1; i>=0; i--){
        if(s[i]==')') close++;
        else {
            open++;
            if(open > close) {
                s[i] = '*';
                open--;
            }
        }
    }
}

int longestValidParentheses(char* s) {
    int n = strlen(s);
    left_pass(s, n);
    right_pass(s, n);
    int len = 0;
    int max_len = 0;
    for(int i=0; i<n; i++) {
        if(s[i]!='*') len++; // (If the character is valid)
        else {
            max_len = max(max_len, len);
            len = 0;
        }
    }
    return max(len, max_len);
}