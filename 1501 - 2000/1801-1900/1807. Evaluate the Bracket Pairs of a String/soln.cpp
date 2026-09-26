class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto& pair : knowledge) dict[pair[0]] = pair[1];
        bool addKey = false;
        string key, res;
        for (char ch : s) {
            if (ch == '(') addKey = true;
            else if (ch == ')') {
                if(dict.count(key) > 0) res+=dict[key];
                else res.push_back('?');
                addKey = false;
                key.clear();
            } 
            else if (addKey) key.push_back(ch);
            else res.push_back(ch);
        }
        return res;
    }
};