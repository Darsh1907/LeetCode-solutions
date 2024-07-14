class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Sort the cuts in descending order
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int h=1, v=1; // Initial number of pieces in each direction
        int i=0, j=0; // Indexes for horizontal and vertical cuts
        int ans=0;      // Total cost
        // Use a greedy approach to take the most expensive cut first
        while (i<horizontalCut.size() && j<verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                ans += horizontalCut[i] * v;
                h++;
                i++;
            } 
            else {
                ans += verticalCut[j] * h;
                v++;
                j++;
            }
        }
        // Add remaining horizontal cuts
        while (i < horizontalCut.size()) {
            ans += horizontalCut[i] * v;
            i++;
        }
        // Add remaining vertical cuts
        while (j < verticalCut.size()) {
            ans += verticalCut[j] * h;
            j++;
        }
        return ans;
    }
};