#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct ActiveCoupon {
        string code;
        string businessLine;
    };
    bool isValidBusinessLine(string s) {
        if(s!="electronics" && s!="grocery" && s!= "pharmacy" && s!= "restaurant") return false;
        return true;
    }
    bool isValidCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(static_cast<unsigned char>(c)) && c != '_') {
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int size = code.size();
        vector<string> res;
        for(int i=0; i<size; i++) {
            if(isActive[i] && isValidCode(code[i]) && isValidBusinessLine(businessLine[i])) {
                res.push_back(code[i]);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};