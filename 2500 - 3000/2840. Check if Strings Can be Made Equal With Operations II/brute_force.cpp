class Solution {
public:
    bool checkStrings(string s1, string s2) {
        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i]==s2[i]) continue;
            for(int j=i+2; j<s1.length(); j=j+2)
            {
                if(s1[j]==s2[i])
                {
                    swap(s1[j],s1[i]);
                    break;
                }
            }
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
};