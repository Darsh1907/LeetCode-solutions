class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> beforeB(n), afterA(n);
        // Compute afterA array 
        int a=0;
        for(int i=n-1; i>=0; i--) {
            afterA[i] = a;
            if(s[i] == 'a') a++;
        }
        // Compute beforeB
        int b = 0;
        for (int i=0; i<n; i++) {
            beforeB[i] = b;
            if(s[i] == 'b') b++;
        }
        // Find the minimum sum of deletions needed
        int minDeletions = n; // Initialize to maximum possible deletions
        for (int i = 0; i < n; ++i) {
            int deletions = afterA[i] + beforeB[i];
            if (deletions < minDeletions) minDeletions = deletions;
        }
        return minDeletions;
    }
};