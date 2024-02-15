class Solution {
public:
    int calcSumSq(int n){
        int sum = 0;
        while(n){
            sum = sum+((n%10)*(n%10));
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while(calcSumSq(n)!=1){
            if(s.find(calcSumSq(n)) == s.end()) {
                s.insert(calcSumSq(n));
                n = calcSumSq(n);
            }
            else return false;
        }
        return true;
    }
};