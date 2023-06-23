#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Remove the spaces from start and end of the string.
        while(s[0]==' ') if(s[0]==' ') s=s.substr(1, s.size()-1);
        while(s[s.size()-1]==' ') if(s[s.size()-1]==' ') s=s.substr(0, s.size()-1);
        // Necessary variables
        string temp = "";
        string result = "";
        // Iterate through the string
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
                if(i==s.size()-1){
                    if(result=="") return temp;
                    else result = temp + ' ' + result;
                }
            }
            else if(s[i]==' ' && s[i-1]!=' '){
                if(result == "") result = temp;
                else result = temp + ' ' + result;
                temp = "";
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string input = "  the   sky is pink  ";
    string output = solution.reverseWords(input);
    cout << "Output: " << output << endl;
    return 0;
}