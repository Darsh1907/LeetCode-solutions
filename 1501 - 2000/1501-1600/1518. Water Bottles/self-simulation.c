int numWaterBottles(int numBottles, int numExchange) {
    int full = 0;
    int empty = numBottles;
    int drunk = empty;
    while (numExchange<=empty) {
        while(numExchange<=empty){
            empty -= numExchange;
            full++;
        }
        empty = empty + full;
        drunk = drunk + full;
        full = 0;
    }
    return drunk;
}