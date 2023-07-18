#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[256] = {0};
        int i;

        for(i=0; s[i]&&t[i]; i++){
            count[s[i]]++;
            count[t[i]]--;
        }

        if(s[i] || t[i]) return false;

        for(i=0; i<256; i++) if(count[i]) return false;

        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    if (solution.isAnagram(s, t)) cout << "The strings are anagrams." << endl;
    else cout << "The strings are not anagrams." << endl;
    return 0;
}