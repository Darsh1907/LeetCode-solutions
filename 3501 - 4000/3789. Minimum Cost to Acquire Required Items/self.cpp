class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0) return 0;
        // If type-3 is not cost effective, never use it
        if (costBoth >= cost1 + cost2) {
            return 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }
        long long totalCost = 0;
        // long long maxBoth = max(need1, need2);
        long long minBoth = min(need1, need2);

        // take minBoth at costBoth because it is cheaper than cost1+cost2
        totalCost = minBoth*costBoth;
        long long remaining1 = max(0LL, need1 - minBoth);
        long long remaining2 = max(0LL, need2 - minBoth);

        if(remaining1) {
            long long costToBuy = min(cost1, costBoth);
            totalCost += 1LL*remaining1*costToBuy;
            return totalCost;
        }

        if(remaining2) {
            long long costToBuy = min(cost2, costBoth);
            totalCost += 1LL*remaining2*costToBuy;
            return totalCost;
        }

        return totalCost;
    }
};