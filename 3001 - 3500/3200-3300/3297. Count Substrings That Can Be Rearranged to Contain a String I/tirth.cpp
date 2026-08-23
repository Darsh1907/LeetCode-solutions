class Solution {
private:
    bool isValid(const vector<int>& current, const vector<int>& target) {
        for (int i=0; i<26; i++) {
            if (current[i] < target[i]) return false;
        }
        return true;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> target(26, 0); // target will hold the required count of each character
        for(char c : word2) target[c - 'a']++;
        long long result = 0;
        vector<int> current(26, 0); // current holds the current count of chars in the selected substring
        int left = 0;
        for (int right = 0; right < n; right++) {
            current[word1[right] - 'a']++;
            while(left<=right && isValid(current, target)) { // if the substring has all valid chars
                result += n - right; // count all possible number of substrings possible within that substrings
                current[word1[left] - 'a']--; // move left
                left++;
            }
        }
        return result;
    }
};