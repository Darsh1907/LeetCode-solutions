#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        unordered_set<char> chars;
        int i=0, j=0, maxSize=0;
        while (j < s.size()){
            while (chars.find(s[j]) != chars.end()){
                chars.erase(s[i]);
                i++;
            }
            maxSize = max(maxSize, j - i + 1);
            chars.insert(s[j]);
            j++;
        }
        return maxSize;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}