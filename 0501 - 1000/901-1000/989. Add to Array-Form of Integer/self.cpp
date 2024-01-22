class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int i=num.size() - 1;
        int carry = 0;
        int sum = 0;
        while(k!=0 || i>=0){
            if(i>=0) sum = (k%10)+num[i]+carry;
            else sum = (k%10)+carry;
            int to_add = sum%10;
            result.push_back(to_add);
            carry = sum/10;
            i--;
            k = k/10;
        }
        if(carry!=0) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};