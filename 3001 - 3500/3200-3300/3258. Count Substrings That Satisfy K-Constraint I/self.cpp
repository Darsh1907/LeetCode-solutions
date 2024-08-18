class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int start = 0, end = 0;
        int count0 = 0, count1 = 0;
        int result = 0;
        while (end < n) {
            if (s[end] == '0') count0++;
            else count1++;
            // Shrink the window until the k-constraint is satisfied
            while (count0 > k && count1 > k) {
                if (s[start] == '0') count0--;
                else count1--;
                start++;
            }
            // All substrings ending at 'end' and starting between 'start' and 'end' are valid
            result += (end - start + 1);
            end++;
        }
        return result;
    }
};