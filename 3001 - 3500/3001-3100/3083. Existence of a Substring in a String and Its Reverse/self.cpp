class Solution {
public:
    bool isSubstringPresent(string s) {
        for(int i=0; i<s.size()-1; i++){
            string temp = s.substr(i, 2);
            reverse(temp.begin(), temp.end());
            if(s.find(temp) != string::npos) return true;
        }
        return false;
    }
};