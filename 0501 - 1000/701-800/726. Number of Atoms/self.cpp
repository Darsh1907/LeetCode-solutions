// Hint 1
// To parse formula[i:], when we see a `'('`, we will parse recursively whatever is inside the 
// brackets (up to the correct closing ending bracket) and add it to our count, multiplying by the 
// following multiplicity if there is one. Otherwise, we should see an uppercase character: we will parse 
// the rest of the letters to get the name, and add that (plus the multiplicity if there is one.)

class Solution {
    inline bool isCaps(char c) {return (c>='A' && c<='Z');}
    inline bool isSmall(char c) {return (c>='a' && c<='z');}
    int getMultiplicity(int& i, string& formula) {
        if(!isdigit(formula[i])) return 1;
        int val = 0;
        while(i<formula.size() && isdigit(formula[i])) {
            val = val*10 + (formula[i]-'0');
            i++;
        }
        // Adjust i because the main loop will increment an extra i
        i--;
        return val;
    }
    void solve(string formula, map<string, int>& mp, int mul) {
        for(int i=0; i<formula.size(); i++) {
            string temp;
            int val = 1;
            if(isCaps(formula[i])) {
                temp.push_back(formula[i]);
                if(i+1 < formula.size() && isSmall(formula[i+1])) temp.push_back(formula[++i]);
                if(i+1 < formula.size() && isdigit(formula[i+1])) val = getMultiplicity(++i, formula);
                mp[temp] += val * mul;
            }
            else if(formula[i]=='(') {
                int j=i+1, count=1;
                while (count > 0) {
                    if (formula[j] == '(') count++;
                    if (formula[j] == ')') count--;
                    j++;
                }
                string newformula = formula.substr(i+1, j-i-2);
                i = j-1;
                int newmul = 1;
                if (i+1 < formula.size() && isdigit(formula[i+1])) newmul = getMultiplicity(++i, formula);
                solve(newformula, mp, mul * newmul);
            }
        }
    }
public:
    string countOfAtoms(string formula) {
        map<string, int> mp;
        solve(formula, mp, 1);
        string result;
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            result += i->first;
            if(i->second > 1) result += to_string(i->second);
        }
        return result;
    }
};