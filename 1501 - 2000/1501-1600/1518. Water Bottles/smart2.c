// Intuition
// You can exchange numExchange empty water bottles from the market with one full water bottle. 
// In the other words, if you have (numExchange-1) empty water bottles, you can borrow one full water bottle 
// from your friend, and drink it, then exchange numExchange empty bottles to one full bottle. 
// Then return it to your friend. Therefore, for every (numExchange-1) empty water bottles, you can gain one 
// free drink!

// Approach
// You can caluclate the extra bottles by dividing your number of bottles by (numExchange-1). 
// However, you always need to borrow one bottle for exchange, so the extra 
// bottles is: (numBottles-1)/(numExchange-1).

// So it is one line solution:
// return numBottles + (numBottles-1)/(numExchange-1)

int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles-1)/(numExchange-1);
}