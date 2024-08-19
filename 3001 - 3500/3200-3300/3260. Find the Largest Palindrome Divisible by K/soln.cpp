class Solution {
    bool isDivisibleBy7(const string& s) {
        int remainder = 0;
        for(char c : s) remainder = (remainder * 10 + (c - '0')) % 7;
        return remainder == 0;
    }
public:    
    string largestPalindrome(int n, int k) {
        if(k==1 || k==3 || k==9) return string(n, '9');
        if(k==2) {
            string res(n, '9');
            res[0] = '8';
            res.back() = '8';
            return res;
        }
        if(k==4) {
            if(n==1) return "8";
            if(n==2) return "88";
            if(n==3) return "888";
            string res(n, '9');
            res[0] = '8';
            res[1] = '8';
            res[n-1] = '8';
            res[n-2] = '8';
            return res;
        }
        if(k==5) {
            string res(n, '9');
            res[0] = '5';
            res.back() = '5';
            return res;
        }
        if(k==8) {
            if(n==1) return "8";
            if(n==2) return "88";
            if(n==3) return "888";
            if(n==4) return "8888";
            if(n==5) return "88888";
            string res(n, '9');
            res[0] = '8';
            res[1] = '8';
            res[2] = '8';
            res[n-1] = '8';
            res[n-2] = '8';
            res[n-3] = '8'; 
            return res;
        }
        if(k == 6) {
            if(n == 1) return "6";
            if(n == 2) return "66";
            if(n == 3) return "888";
            if(n == 4) return "8778";
            // if n is even, add "77" in between
            if(n%2==0) return "8" + string((n-4)/2, '9') + "77" + string((n-4)/2, '9') + "8";
            // if n is odd, add "8" in between
            else return "8" + string((n-3)/2, '9') + "8" + string((n-3)/2, '9') + "8";
        }
        if(k==7) {
            string ans(n, '9');
            // if n is odd
            if(n%2) {
                for(char i='9'; i>=0; i--) {
                    ans[n/2] = i;
                    if(isDivisibleBy7(ans)) return ans;
                }
            }
            else {
                for(char i='9'; i>=0; i--) {
                    ans[n/2] = i;
                    ans[n/2 - 1] = i;
                    if(isDivisibleBy7(ans)) return ans;
                }
            }
        }
        return "";
    }
};