class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int total = numBottles;
        while(numExchange <= total ) {
            total -= numExchange;
            total++;
            numExchange++;
            ans++;
        }
        return ans;
    }
}