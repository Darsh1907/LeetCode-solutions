class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return static_cast<long long>(nums[0]) * nums[0];
        // Step 1: Create prefix and suffix GCD arrays
        vector<int> prefixGCD(n, 0), suffixGCD(n, 0);
        prefixGCD[0] = nums[0];
        for (int i=1; i<n; i++) prefixGCD[i] = gcd(prefixGCD[i - 1], nums[i]);
        suffixGCD[n - 1] = nums[n - 1];
        for(int i=n-2; i>=0; i--) suffixGCD[i] = gcd(suffixGCD[i + 1], nums[i]);
        // Step 2: Calculate initial LCM of the entire array
        long long totalLCM = nums[0];
        for(int i = 1; i < n; ++i) totalLCM = lcm(totalLCM, nums[i]);
        // Step 3: Calculate max factor score with and without each element
        long long maxFactorScore = totalLCM * prefixGCD[n - 1]; // factor score without removing any element
        for(int i = 0; i < n; ++i) {
            // GCD without nums[i]
            int gcdWithoutElement = (i == 0) ? suffixGCD[1] : (i == n - 1) ? prefixGCD[n - 2] : gcd(prefixGCD[i - 1], suffixGCD[i + 1]);
            // LCM without nums[i]
            long long lcmWithoutElement = 1;
            for (int j = 0; j < n; ++j) {
                if(j!=i) lcmWithoutElement = lcm(lcmWithoutElement, nums[j]);
            }
            // Calculate factor score and update maximum
            maxFactorScore = max(maxFactorScore, gcdWithoutElement * lcmWithoutElement);
        }
        return maxFactorScore;
    }
    
private:
    // Utility function to calculate LCM of two numbers
    long long lcm(long long a, long long b) {return (a / gcd(a, b)) * b;}
};