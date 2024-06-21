class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        string temp;
        int open = 0;
        int close = 0;
        for(int i=0; i<s.size(); i++) {
            while(open!=close || open==0) { // because s is always valid
                if(s[i]=='(') open++;
                else close++;
                temp.push_back(s[i]);
                if(open!=close) i++;
            }
            result = result + temp.substr(1, temp.size()-2);
            temp = "";
            open = 0;
            close = 0;
        }
        return result;
    }
};