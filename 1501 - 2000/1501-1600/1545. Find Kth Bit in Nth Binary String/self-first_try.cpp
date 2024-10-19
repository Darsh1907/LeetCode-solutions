class Solution {
    string inverse(string& s) {
        string res;
        for(char ch: s) {
            if(ch=='1') res.push_back('0');
            else res.push_back('1');
        }
        return res;
    }
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=0; i<n-1; i++) {
            string s_rev_inv = inverse(s);
            reverse(s_rev_inv.begin(), s_rev_inv.end());
            s = s + "1" + s_rev_inv;
        }
        return s[k-1];
    }
};