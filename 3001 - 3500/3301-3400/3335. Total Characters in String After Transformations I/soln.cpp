class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> cnt(26, 0);
        for(char ch : s) cnt[ch - 'a']++;
        for(int j=0; j<t; j++) {
            vector<long long> tmp(26, 0);
            for (int i=0; i<26; i++) {
                // if char is 'z'
                if(i==25) {
                    tmp[0] = (tmp[0] + cnt[i]) % MOD;
                    tmp[1] = (tmp[1] + cnt[i]) % MOD;
                }
                // if char is something else
                else tmp[i + 1] = (tmp[i + 1] + cnt[i]) % MOD;
            }
            cnt = tmp;
        }
        // get final length of size (sum of cnt array)
        long long len = 0;
        for (long long num : cnt) len = (len + num) % MOD;
        return len;
    }
};