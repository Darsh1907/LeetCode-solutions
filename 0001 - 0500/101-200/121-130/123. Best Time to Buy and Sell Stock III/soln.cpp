class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Variables to track max profit for one transaction
        int max_profit = 0;
        int min_price = prices[0];
        // Step 1: Calculate maximum profit for the first transaction
        vector<int> left_max_profit(n, 0);
        for (int i=1; i<n; i++) {
            min_price = min(min_price, prices[i]);
            left_max_profit[i] = max(left_max_profit[i-1], prices[i] - min_price);
        }
        // Step 2: Calculate maximum profit for the second transaction in reverse
        int max_price = prices[n-1];
        for (int i=n-2; i>=0; i--) {
            max_price = max(max_price, prices[i]);
            // Combine current profit from the second transaction with the max profit from the first transaction
            max_profit = max(max_profit, left_max_profit[i] + (max_price - prices[i]));
        }
        return max_profit;
    }
};