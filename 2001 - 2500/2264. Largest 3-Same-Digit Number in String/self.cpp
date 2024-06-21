class Solution {
public:
    string largestGoodInteger(string num) {
        char curr = '0';
        bool exist = false;
        string result;
        for(int i=0; i<num.size()-2; i++) {
            if(num[i]==num[i+1] && num[i+1]==num[i+2]) {
                curr = max(curr, num[i]);
                exist = true;
                i += 2;
            }
        }
        if(exist) {
            for(int i=0; i<3; i++) result.push_back(curr);
        }
        return result;
    }
};