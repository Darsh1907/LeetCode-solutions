int max(int a, int b) {if(a>=b) return a; return b;}

int getmaxHeight(int red, int blue) {
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
    if(red==blue) return getmaxHeight(red, blue);
    int maxHeightRed = getmaxHeight(red, blue); // get maximum height possible considering red as root node
    int maxHeightBlue = getmaxHeight(blue, red); // considering blue as red and red as blue to get the maximum height of the triangle with blue as root
    return max(maxHeightRed, maxHeightBlue);
}