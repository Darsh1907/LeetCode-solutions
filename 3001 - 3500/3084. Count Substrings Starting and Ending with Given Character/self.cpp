class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        int n = s.length();
        int occurrences = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == c) {
                occurrences++;
                count += occurrences;
            }
        }
        return count;
    }
};