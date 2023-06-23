#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Remove leading and trailing spaces
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
            return !isspace(ch);
        }));
        s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), s.end());
        // Reverse the entire string
        reverse(s.begin(), s.end());
        // Reverse each word
        int start = 0;
        int end = 0;
        while (end < s.length()) {
            if(s[end] != ' ') {
                start = end;
                while(end < s.length() && s[end] != ' ') end++;
                reverse(s.begin() + start, s.begin() + end);
            }
            else end++;
        }
        // Remove extra spaces between words
        string result;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            if(!result.empty()) result += ' ';
            result += word;
        }
        return result;
    }
};

int main() {
    Solution solution;
    string input = "  the sky is  blue  ";
    string output = solution.reverseWords(input);
    cout << "Output: " << output << endl;
    return 0;
}