// Using monotonic Stack

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        st.push(0);
        for(int i=n-1; i>=0; i--){
            while(st.top() > prices[i]) st.pop();
            int discount = st.top();
            st.push(prices[i]);
            prices[i] = prices[i] - discount;
        }
        return prices;
    }
};