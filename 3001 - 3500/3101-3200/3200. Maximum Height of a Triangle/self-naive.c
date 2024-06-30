int max(int a, int b) {if(a>=b) return a; return b;}

// If the first node is blue
int getmaxHeightBlue(int red, int blue) {
    int res = 0;
    int currRed = 0;
    int totakeRed = 2;
    int totakeBlue = 1;
    int currBlue = 0;
    while(1){
        if(currBlue+totakeBlue <= blue) {
            currBlue += totakeBlue;
            totakeBlue += 2;
            res++;
        }
        else break;
        if(currRed+totakeRed <= red) {
            currRed += totakeRed;
            totakeRed += 2;
            res++;
        }
        else break;
    }
    return res;
}

// If the first node is red
int getmaxHeightRed(int red, int blue) {
    int res = 0;
    int currRed = 0;
    int totakeRed = 1;
    int totakeBlue = 2;
    int currBlue = 0;
    while(1){
        if(currRed+totakeRed <= red) {
            currRed += totakeRed;
            totakeRed += 2;
            res++;
        }
        else break;
        if(currBlue+totakeBlue <= blue) {
            currBlue += totakeBlue;
            totakeBlue += 2;
            res++;
        }
        else break;
    }
    return res;
}

int maxHeightOfTriangle(int red, int blue) {
    if(red==blue) return getmaxHeightRed(red, blue);
    int maxHeightRed = getmaxHeightRed(red, blue);
    int maxHeightBlue = getmaxHeightBlue(red, blue);
    return max(maxHeightRed, maxHeightBlue);
}