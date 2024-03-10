class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, vector<string> chars) {
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0';
        string value = chars[number];
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, chars);
            output.pop_back(); // For second possibility of 'index', we need to remove the first possibility
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string output;
        int index = 0;
        vector<string> chars {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, chars);
        return ans;
    }
};