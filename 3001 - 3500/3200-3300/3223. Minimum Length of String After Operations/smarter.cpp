class Solution {
public:
    int minimumLength(string s) {
        vector<int> a(26);
        for(auto x:s) a[x-'a']+=1;
        int ans=0;
        for(int i=0; i<26; i++) {
            if(a[i]%2) ans+=1;
            else if(a[i]) ans+=2;
        }
        return ans;
    }
};