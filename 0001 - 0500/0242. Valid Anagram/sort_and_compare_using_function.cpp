class Solution {
public:
    bool isAnagram(string s, string t) {
        int flag=0;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s.compare(t)==0) flag=1;
        else flag=0;
        
        return flag;
    }
};