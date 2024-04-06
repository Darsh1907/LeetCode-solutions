class Solution {
private:
    void left_pass(string& s){
        int open = 0;
        int close = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') open++;
            else if(s[i]==')') {
                close++;
                if(close > open) {
                    s[i]='*';
                    close--;
                }
            }
        }
    }
    void right_pass(string& s){
        int open = 0;
        int close = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==')') close++;
            else if(s[i]=='(') {
                open++;
                if(open > close) {
                    s[i]='*';
                    open--;
                }
            }
        }
    }
public:
    string minRemoveToMakeValid(string s) {
        left_pass(s);
        right_pass(s);
        string result;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='*') result.push_back(s[i]);
        }
        return result;
    }
};