class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int k = 0;
        for (int num :  nums) {
            int d = 0;
            while (num != 0) {
                num /= 10;
                d++;
            }
            if (d % 2 == 0) ++k;
        }

        return k;
    }
};