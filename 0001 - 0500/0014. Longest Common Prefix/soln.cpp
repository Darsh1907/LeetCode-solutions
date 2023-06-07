#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Base case: If the input vector is empty, return an empty string
        if (strs.empty()) {
            return "";
        }

        // Iterate over the characters in the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];

            // Check if the character is common in all strings
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    // If the character is not common or the string is exhausted, return the prefix found so far
                    return strs[0].substr(0, i);
                }
            }
        }

        // Return the entire first string as the common prefix
        return strs[0];
    }
};

int main() {
    // Test case
    vector<string> strs = {"flower", "flow", "flight"};
    Solution solution;

    string commonPrefix = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << commonPrefix << endl;

    return 0;
}