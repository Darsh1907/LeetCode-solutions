class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int diff[26];
        int ans = 0;
        for(int i=0; i<s.length(); i++) diff[s[i]-'a'] = i;
        for(int i=0; i<t.length(); i++) {
            diff[t[i]-'a'] -= i;
            if(diff[t[i]-'a'] < 0) ans -= diff[t[i]-'a'];
            else ans += diff[t[i]-'a'];
        }
        return ans;
    }
};