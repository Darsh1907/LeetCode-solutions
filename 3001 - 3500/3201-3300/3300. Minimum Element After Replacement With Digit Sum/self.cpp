class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int num: nums) {
            int digit_sum = 0;
            while(num) {
                int dig = num%10;
                num = num/10;
                digit_sum += dig;
            }
            res = min(res, digit_sum);
        }
        return res;
    }
};