#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int flag=0;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s.compare(t)==0) flag=1;
        else flag=0;
        
        return flag;
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