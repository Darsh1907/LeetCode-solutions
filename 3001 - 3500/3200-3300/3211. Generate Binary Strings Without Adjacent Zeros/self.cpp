class Solution {
    void getAns(int size, vector<string>& result, string temp) {
        if(temp.size()==size) {
            result.push_back(temp);
            return;
        }
        if (temp.back() == '0') {
            temp.push_back('1');
            getAns(size, result, temp);
            return;
        }
        // if last character is 1, we can push both 1 and 0
        // pushing 0
        temp.push_back('0');
        getAns(size, result, temp);
        // pushing 1
        temp[temp.size()-1] = '1';
        getAns(size, result, temp);
        return;
    }
public:
    vector<string> validStrings(int n) {
        if(n==1) return {"1", "0"};
        if(n==2) return {"01", "10", "11"};
        vector<string> result;
        getAns(n, result, "0");
        getAns(n, result, "1");
        return result;
    }
};