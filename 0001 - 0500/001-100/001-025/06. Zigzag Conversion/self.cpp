class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        // int size = s.szie();
        vector<int> belongsTo;

        bool flag=true;
        int belongrow = 1;
        for(int i=0; i<s.size(); i++){
            belongsTo.push_back(belongrow);
            if(belongrow == 1) flag = true;
            else if(belongrow == numRows) flag = false;
            if(flag==true) belongrow++;
            else belongrow--;
        }

        string result;
        int temp = 1;
        while(temp<=numRows){
            for(int i=0; i<s.size(); i++){
                if(belongsTo[i]==temp) result.push_back(s[i]);
            }
            temp++;
        }
        
        return result;
    }
};