#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";

        int minLength = strs[0].size();
        int minindex = 0;
        for(int i=1; i<strs.size(); i++){
            if(strs[i].size()<minLength){
                minLength=strs[i].size();
                minindex = i;
            }
        }

        for(int i=0; i<minLength; i++){
            for(int j=0; j<strs.size(); j++){
                if(strs[minindex][i] != strs[j][i]){
                    return strs[minindex].substr(0, i);
                }
            }
        }

        return strs[minindex];
    }
};

int main() {
    // Test case
    vector<string> strs = {"flower", "flow", "flower", "flower"};
    Solution solution;

    string commonPrefix = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << commonPrefix << endl;

    return 0;
}