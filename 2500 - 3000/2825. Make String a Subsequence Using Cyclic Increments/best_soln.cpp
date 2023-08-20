class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        const int m = str1.length(), n = str2.length();
        if (m < n) return false;
        int j = 0;
        for (int i = 0; i < m && j < n; ++i) {
            if(str2[j] == str1[i] || str2[j] == str1[i] + 1 || (str2[j] == 'a' && str1[i] == 'z')) ++j;
        }
        return j >= n;
    }
};