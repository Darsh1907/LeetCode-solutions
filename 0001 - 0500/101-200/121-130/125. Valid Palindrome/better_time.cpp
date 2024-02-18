class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                t += tolower(s[i]);
            }
        }
        int start = 0;
        int end = t.size()-1;
        while (start < end) {
            if (t[start] == t[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};