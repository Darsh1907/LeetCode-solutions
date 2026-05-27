class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefixN(n + 1, 0); // prefixN[i] = number of 'N' in [0, i)
        for (int i = 0; i < n; i++) {
            prefixN[i + 1] = prefixN[i] + (customers[i] == 'N');
        }
        vector<int> suffixY(n + 1, 0); // suffixY[i] = number of 'Y' in [i, n)
        for (int i = n - 1; i >= 0; i--) {
            suffixY[i] = suffixY[i + 1] + (customers[i] == 'Y');
        }
        int minPenalty = INT_MAX;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            int penalty = prefixN[i] + suffixY[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                res = i;
            }
        }
        return res;
    }
};