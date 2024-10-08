class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char, int> freq1, freq2;
        // Count frequencies of characters in both strings
        for (char ch : word1) freq1[ch]++;
        for (char ch : word2) freq2[ch]++;
        // If the sets of characters are not the same, return false
        if (freq1.size() != freq2.size()) return false;
        // every occurrence of existing character can be replace only into another existing character
        for (auto& pair : freq1) {
            if (freq2.find(pair.first) == freq2.end()) return false;
        }
        // Store frequencies in vectors and sort them
        vector<int> counts1, counts2;
        for (const auto& pair : freq1) counts1.push_back(pair.second);
        for (const auto& pair : freq2) counts2.push_back(pair.second);
        // sort vectors for comparison
        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());
        // Compare sorted frequency vectors
        return counts1 == counts2;
    }
};