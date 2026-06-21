#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // It is always optimal to buy the least expensive ice cream bar first.
        sort(costs.begin(), costs.end());
        int i=0;
        int res = 0;
        while(coins && i<costs.size()) {
            // if no more ice cream are affordable with the remainig coins, return.
            if(costs[i] > coins) return res;
            // take ice cream
            res++;
            coins = coins - costs[i++]; // increment i after taking the ith ice cream
        }
        return res;
    }
};