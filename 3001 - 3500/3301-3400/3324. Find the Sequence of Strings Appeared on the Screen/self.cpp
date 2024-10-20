class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string curr;
        for(char ch: target) {
            curr.push_back('a');
            res.push_back(curr);
            while(curr.back() != ch) {
                curr.back()++;
                res.push_back(curr);
            }
        }
        return res;
    }
};