class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size() - 1;
        while (true) {
            if (!(++digits[size] >= 10)) return digits;
            digits[size] = 0;
            if (size != 0) {
                if (!(++digits[--size] > 9)) return digits;
            }
            else{
                digits[0] = 1;
                digits.push_back(0);
                return digits;
            }
        }
    }
};