#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i=(s.size()-1); i>=0; i--){
            if(count==0 && s[i]==' ')
                count = 0;
            else if(s[i]!=' ')
                count++;
            else if(s[i]==' ' && count!=0)
                break;
        }
        return count;
    }
};

int main() {
    // Example usage
    string s = "Hello World";

    Solution solution;
    int length = solution.lengthOfLastWord(s);

    cout << "Length of last word: " << length << endl;

    return 0;
}