class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, l = 0, r = 0;
        while (r<prices.size()){
            if(prices[r]>prices[l]) result=max(result, prices[r]-prices[l]);
            else l = r;
            r++;
        }
        return result;
    }
};