class Solution {
// Let total be the number of equal adjacent pairs in the original string, including the circular pair between the last and first characters.
// For every rotation, the count can only be:

// total → occurs n - total times
// total - 1 → occurs total times
// So we only need to calculate total once.

// Each rotation excludes exactly one circular adjacent pair. Its score is total - 1 if the excluded pair has equal characters, and total otherwise.
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int totalAdj = 0;
        if(s[0]==s[n-1]) totalAdj++;
        for(int i=1; i<n; i++) {
            if(s[i] == s[i-1]) totalAdj++;
        }
        if(k == totalAdj) return n - totalAdj;
        if(k == totalAdj-1) return totalAdj;
        return 0;
    }
};