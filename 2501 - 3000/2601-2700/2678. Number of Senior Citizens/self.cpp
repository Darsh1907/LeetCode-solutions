class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i=0; i<details.size(); i++) {
            int num1 = details[i][11] - '0';
            int num2 = details[i][12] - '0';
            if(num1 > 5) {
                if(num1==6 && num2==0) continue;
                count++;
            }
        }
        return count;
    }
};