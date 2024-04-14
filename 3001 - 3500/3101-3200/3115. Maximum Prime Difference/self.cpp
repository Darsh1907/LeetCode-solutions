class Solution {
private:
    bool isPrime(int n) {
        if(n<=1) return false; // 1 and numbers less than 1 are not prime
        if(n<=3) return true; // 2 and 3 are prime
        if(n%2==0 || n%3==0) return false; // numbers divisible by 2 or 3 are not prime
        // Loop only until square root of n
        for (int i=5; i*i<=n; i+=6) {
            if(n%i==0 || n%(i+2)==0) return false; // if n is divisible by any number between i and i+2, it's not prime
        }
        return true; // if none of the conditions above met, n is prime
    }
    int firstPrime(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(isPrime(nums[i])) return i;
        }
        return -1;
    }
    int lastPrime(vector<int>& nums) {
        for(int i=nums.size()-1; i>=0; i--) {
            if(isPrime(nums[i])) return i;
        }
        return -1;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int firstprime = firstPrime(nums);
        int lastprime = lastPrime(nums);
        return lastprime-firstprime;
    }
};