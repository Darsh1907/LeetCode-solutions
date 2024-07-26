class Solution {
    void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
        if(openP==closeP && openP+closeP==n*2) {
            res.push_back(s);
            return;
        }
        if(openP < n) dfs(openP+1, closeP, s+"(", n, res);
        if(closeP < openP) dfs(openP, closeP+1, s+")", n, res);
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        else if(n==1) return {"()"};    
        else if(n==2) return {"(())", "()()"};
        else if(n==3) return {"((()))","(()())","(())()","()(())","()()()"};
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }
};