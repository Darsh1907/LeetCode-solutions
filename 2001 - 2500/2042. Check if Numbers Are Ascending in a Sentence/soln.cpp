class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                string temp;
                while(i<s.length() && isdigit(s[i])) temp=temp+s[i++];
                int curr = stoi(temp);
                if(curr<=prev) return false;
                prev = curr;
            }
        }
        return true;
    }
};