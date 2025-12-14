class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseWords(string s) {
        vector<string> words;
        string word;
        for (char c : s) {
            if (c == ' ') {
                words.push_back(word);
                word.clear();
            } else {
                word.push_back(c);
            }
        }
        words.push_back(word);
        int firstVowelCount = 0;
        for (char c : words[0]) {
            if (isVowel(c)) firstVowelCount++;
        }
        for (int i = 1; i < words.size(); i++) {
            int vowelCount = 0;
            for (char c : words[i]) {
                if (isVowel(c)) vowelCount++;
            }
            if (vowelCount == firstVowelCount) {
                reverse(words[i].begin(), words[i].end());
            }
        }
        string result;
        for(int i=0; i<words.size(); i++) {
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};