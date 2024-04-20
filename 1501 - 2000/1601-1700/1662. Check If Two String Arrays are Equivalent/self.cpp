class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word_1 = word1[0];
        string word_2 = word2[0];
        for(int i=1; i<word1.size(); i++) word_1 = word_1 + word1[i];
        for(int i=1; i<word2.size(); i++) word_2 = word_2 + word2[i];
        return word_1 == word_2;
    }
};