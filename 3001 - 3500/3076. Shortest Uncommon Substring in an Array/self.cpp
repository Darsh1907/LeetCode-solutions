class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> answer;
        for(int i=0; i<arr.size(); i++) {
            string smallestSubstring;
            bool found = false;
            for (int p=0; p<arr[i].size(); p++) {
                for (int q=1; q<=arr[i].size()-p; q++) {
                    string substr = arr[i].substr(p, q);
                    bool unique = true;
                    for(int j=0; j<arr.size(); j++) {
                        if (j!=i && arr[j].find(substr)!=string::npos) {
                            unique = false;
                            break;
                        }
                    }
                    if (unique) {
                        if (!found || substr.size() < smallestSubstring.size() || (substr.size() == smallestSubstring.size() && substr < smallestSubstring)) {
                            smallestSubstring = substr;
                            found = true;
                        }
                    }
                }
            }
            answer.push_back(smallestSubstring);
        }
        return answer;
    }
};