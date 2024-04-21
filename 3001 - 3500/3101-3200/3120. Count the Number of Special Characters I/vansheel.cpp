class Solution {
public:
    int numberOfSpecialChars(string word) {
        string dup="";
        int count=0;
        set<char> s;
        for(int i=0;i<word.size();i++) s.insert(word[i]);
        for(auto a:s) dup+=a;
        for(int i=0;i<dup.size();i++)
        {
            if('A' <= dup[i] && dup[i] <= 'Z') 
            {
             if(s.find(tolower(dup[i]))!=s.end()) count++;   
            }
        }
        return count;
    }
};