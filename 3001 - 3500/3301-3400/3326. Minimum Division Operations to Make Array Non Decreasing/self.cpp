class Solution {
    unordered_map<int, int> dp; // num->greatest Divisor
private:
    // Helper function to find the greatest proper divisor of a number
    int greatestProperDivisor(int num) {
        auto it = dp.find(num);
        if(it!=dp.end()) return it->second;
        // Return the greatest proper divisor of num
        for (int i = num / 2; i >= 1; --i) {
            if(num % i == 0) {
                dp[num] = i;
                return i;
            }
        }
        dp[num] = 1;
        return 1; // If no proper divisor found, return 1
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for(int i=n-2; i>=0; i--) {
            while(nums[i] > nums[i+1]) {
                int divisor = greatestProperDivisor(nums[i]);
                if(divisor==1) return -1;
                nums[i] = nums[i]/divisor;
                ops++;
            }
        }
        return ops;
    }
};