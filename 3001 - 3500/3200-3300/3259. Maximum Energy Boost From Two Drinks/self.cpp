class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<long long> dpA(n), dpB(n);
        dpA[0] = energyDrinkA[0];
        dpB[0] = energyDrinkB[0];
        for (int i = 1; i < n; i++) {
            dpA[i] = dpA[i-1] + energyDrinkA[i];
            dpB[i] = dpB[i-1] + energyDrinkB[i];   
            if (i > 1) {
                dpA[i] = max(dpA[i], dpB[i-2] + energyDrinkA[i]);
                dpB[i] = max(dpB[i], dpA[i-2] + energyDrinkB[i]);
            }
        }
        return max(dpA[n-1], dpB[n-1]);
    }
};