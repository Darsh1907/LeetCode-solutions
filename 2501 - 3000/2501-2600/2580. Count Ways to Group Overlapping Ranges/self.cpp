// Hint1: Can we use sorting here?
// Hint2: Sort the ranges and merge the overlapping ranges. Then count number of non-overlapping ranges.
// Hint3: How many ways can we group these non-overlapping ranges?

#define MOD 1000000007
// Number of ways is 2^(number of components) - 2
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        // Sort the ranges based on their start value
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> components;
        for (const vector<int>& range : ranges) {
            int start = range[0];
            int end = range[1];
            // If the current range overlaps with the last component, merge them
            if (!components.empty() && start <= components.back()[1]) {
                components.back()[1] = max(components.back()[1], end);
            } 
            // Otherwise, start a new component
            else components.push_back(range);
        }
        // Calculate 2^number_of_components % MOD
        int numComponents = components.size();
        long long result = 1;  // Use long long to handle large powers
        for (int i=0; i<numComponents; i++) result = (result * 2) % MOD;
        // Number of ways is 2^(number of components)
        return result;  // Adding MOD before modulo to handle negative results
    }
};