#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        int size = len1 + len2;
        char* result = (char*)malloc((size + 1) * sizeof(char));

        int i, j, k;
        i = j = k = 0;

        while (i<len1 && j<len2) {
            result[k] = word1[i];
            k++;
            i++;
            result[k] = word2[j];
            k++;
            j++;
        }

        while (i < len1){
            result[k] = word1[i];
            k++;
            i++;
        }

        while (j < len2){
            result[k] = word2[j];
            k++;
            j++;
        } 

        result[k] = '\0';

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
