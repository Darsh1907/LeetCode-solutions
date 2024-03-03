#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        set<char> vowels({'a', 'A', 'e', 'E', 'i', 'I', 'O', 'o', 'U', 'u'});
        while (left < right) {
            while(left<right && vowels.find(s[left])==vowels.end()) left++;
            while(left<right && vowels.find(s[right])==vowels.end()) right--;
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;
    string reversed = solution.reverseVowels(input);
    cout << "Reversed vowels: " << reversed << endl;
    return 0;
}