class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        unordered_set<char> lower;
        unordered_set<char> upper;
        for(int i=0; i<word.size(); i++) {
            if(word[i] < 91) upper.insert(word[i]);
            else lower.insert(word[i]);
        }
        for(auto i=upper.begin(); i!=upper.end(); i++) {
            if(lower.find(*i + 32) != lower.end()) count++;
        }
        return count;
    }
};