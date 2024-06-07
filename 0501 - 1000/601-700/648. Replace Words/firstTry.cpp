// This is actually quesiton of Tries

class Solution {
private:
    vector<string> getWords(string& sentence) {
        vector<string> words;
        istringstream stream(sentence);
        string word;
        while(stream >> word) words.push_back(word);
        return words;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;
        for(int i=0; i<dictionary.size(); i++) dict.insert(dictionary[i]); 
        string result;
        vector<string> words = getWords(sentence);
        for(int i=0; i<words.size(); i++) {
            for(int j=1; j<=words[i].size(); j++) {
                if(dict.find(words[i].substr(0, j)) != dict.end() || j==words[i].size()) {
                    result = result + words[i].substr(0, j);
                    break;
                }
            }
            if(i!=words.size()-1) result += " ";
        }
        return result;
    }
};