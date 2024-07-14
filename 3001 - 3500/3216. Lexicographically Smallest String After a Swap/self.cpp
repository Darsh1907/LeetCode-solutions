class Solution {
    bool hasSameParity(int a, int b) {
        if(a%2==0 && b%2==0) return true;
        if(a%2==1 && b%2==1) return true;
        return false;
    }
public:
    string getSmallestString(string s) {
        for(int i=1; i<s.size(); i++) {
            if(hasSameParity(s[i], s[i-1]) && s[i]<s[i-1]) {
                swap(s[i], s[i-1]);
                break;
            }
        }
        return s;
    }
};