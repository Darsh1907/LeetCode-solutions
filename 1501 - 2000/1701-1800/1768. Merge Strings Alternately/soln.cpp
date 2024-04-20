#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        while (i<word1.length() || i < word2.length()) {
            if(i<word1.length()) result += word1[i];
            if(i<word2.length()) result += word2[i];
            i++;
        }
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    // Test case 1
    string word1 = "abc";
    string word2 = "def";
    string result1 = solution.mergeAlternately(word1, word2);
    cout << "Result 1: " << result1 << endl;
    // Test case 2
    string word3 = "abcd";
    string word4 = "efgh";
    string result2 = solution.mergeAlternately(word3, word4);
    cout << "Result 2: " << result2 << endl;
    // Add more test cases as needed
    return 0;
}
