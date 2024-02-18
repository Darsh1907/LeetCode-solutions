int max(int a, int b){
    if(a>b) return a;
    return b;
}

int maxProfit(int* prices, int pricesSize) {
    int result = 0, l = 0, r = 0;
    while (r < pricesSize) {
        if(prices[r] > prices[l]) result=max(result, prices[r]-prices[l]);
        else l = r;
        r++;
    }
    return result;
}