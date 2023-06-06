#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
        for(i=0; i<256; i++)
            if(count[i]) return false;
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Your code here
        int strslen=strs.size();

        vector<vector<string>> result;
        vector<string> temp;
        int visited[strslen] = {0};

        for(int i=0; i<strslen; i++){
            if (!visited[i]){
                visited[i]=true;
                temp.clear();
                temp.push_back(strs[i]);
                for(int j=i+1; j<strslen; j++){
                    if(!visited[j]){
                        if(isAnagram(strs[i], strs[j])){
                            visited[j]=true;
                            temp.push_back(strs[j]);
                        }
                    }
                }
                result.push_back(temp);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    cout << "Grouped Anagrams: " << endl;
    for (const auto& group : result1) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Test case 2
    vector<string> strs2 = {"cat", "dog", "tac", "god", "act"};
    vector<vector<string>> result2 = solution.groupAnagrams(strs2);
    cout << "Grouped Anagrams: " << endl;
    for (const auto& group : result2) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Add more test cases if needed
    
    return 0;
}