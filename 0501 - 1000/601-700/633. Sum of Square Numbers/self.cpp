#include<cmath>
#include<math.h>
#include<iostream>

using namespace std;

class Solution {
bool isPerfectSquare(int n) {
    // If ceil and floor are equal the number is a perfect square
    double sqrtn = sqrt(n);
    if (ceil(sqrtn) == floor(sqrtn)) return true;
    else return false;
}
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int sqrtc = sqrt(c);
        while(i<sqrtc+1) {
            int squarei = i*i;
            if(isPerfectSquare(c - squarei)) return true;
            i++;
        }
        return false;
    }
};

int main() {
    Solution s;
    std::cout << s.judgeSquareSum(5) << std::endl;
    std::cout << s.judgeSquareSum(3) << std::endl;
    std::cout << s.judgeSquareSum(4) << std::endl;
    std::cout << s.judgeSquareSum(2) << std::endl;
    std::cout << s.judgeSquareSum(1) << std::endl;
    std::cout << s.judgeSquareSum(0) << std::endl;
    std::cout << s.judgeSquareSum(1000000) << std::endl;
    return 0;
}