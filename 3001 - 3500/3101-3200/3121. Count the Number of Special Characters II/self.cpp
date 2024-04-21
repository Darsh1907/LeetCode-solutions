class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        unordered_map<char, int> lower;
        unordered_map<char, int> upper;
        for(int i=0; i<word.size(); i++) {
            if(word[i]<91) {
                if(upper.find(word[i]) == upper.end()) upper[word[i]] = i;
            }
            lower[word[i]] = i;
        }
        for(auto i=upper.begin(); i!=upper.end(); i++) {
            if(lower.find(i->first + 32) != lower.end()) {
                if(lower[i->first + 32] < i->second) count++;
            }
        }
        return count;
    }
};