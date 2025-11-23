#include <vector>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long newNum = 0;
        vector<int> nonZero;
        int n_dup = n;
        while(n>0) {
            int digit = n%10;
            if(digit>0) {
                nonZero.push_back(digit); 
                sum += digit;
            }
            n = n/10;
        }
        for(int i=nonZero.size()-1; i>=0; i--) {
            int nonZeroDigit = nonZero[i];
            newNum = (newNum*10) + nonZeroDigit;
        }
        return newNum * sum;
    }
};