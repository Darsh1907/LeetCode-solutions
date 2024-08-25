class Solution {
    string padNumber(int num) {
        string str = to_string(num);
        return string(6 - str.length(), '0') + str;
    }
    bool almostEqual(int num1, int num2) {
        if(num1==num2) return true;
        string strnum1 = padNumber(num1);
        string strnum2 = padNumber(num2);
        int i=0;
        pair<int, int> toSwap = {-1, -1};
        int diff = 0;
        while(i<strnum1.size() && i<strnum2.size()) {
            if(strnum1[i] != strnum2[i]) {
                // first time difference
                if(toSwap.first==-1) {
                    diff++;
                    toSwap = {strnum2[i], strnum1[i]};
                }
                // second anamoly
                else {
                    if(toSwap.first != strnum1[i] || toSwap.second != strnum2[i]) return false;
                    // dont let any other number swap
                    else toSwap = {-2, -2};
                }
            }
            i++;
        }
        if(diff > 1) return false;
        // in case of only one anamoly
        if(toSwap.first>0 || toSwap.second>0) return false;
        // cout << num1 << " and " << num2 << " are almostEqual" << endl;
        return true;
    }
public:
    int countPairs(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(almostEqual(nums[i], nums[j])) count++;
            }
        }
        return count;
    }
};