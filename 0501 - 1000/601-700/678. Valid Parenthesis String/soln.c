// References:
// NeetCode: https://www.youtube.com/watch?v=QhPdNS143Qg

bool checkValidString(char* s) {
    int size = strlen(s);
    int minClose=0, maxClose=0, close=0;
    for(int i=0; i<size; i++) {
        if(s[i]=='(') {
            minClose++;
            maxClose++;
        }
        else if(s[i]=='*') {
            minClose--;
            maxClose++;
        }
        else {
            maxClose--;
            minClose--;
        }
        if(maxClose < 0) return false;
        if(minClose < 0) minClose = 0;
    }
    return (minClose == 0);
}