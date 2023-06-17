#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If there are no strings in the vector, return ""
        if(strs.empty()) return "";

        // First initialize the minimum length and the index of minimum length string as the first string of the vector.
        // We'll change it later if necessary
        int minLength = strs[0].size();
        int minindex = 0;

        // Check for the minimum length string and its index in the vector
        for(int i=1; i<strs.size(); i++){
            if(strs[i].size()<minLength){
                minLength=strs[i].size();
                minindex = i;
            }
        }
        // The minimum length string and its index in the vector is found

        // Our loop will iterate only for the "minimum length" times and check where exactly the common prefix ends.
        // First loop to iterate over the letters of the string.
        for(int i=0; i<minLength; i++){
            // Second loop to iterate over different strings of the vector
            for(int j=0; j<strs.size(); j++){
                if(strs[minindex][i] != strs[j][i]){
                    return strs[minindex].substr(0, i);
                }
            }
        }

        // If the loop dont return anything, it means we have reached the limit of minimum length string, with
        // every character being common in each string. So we return the minimum length string as the solution.
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