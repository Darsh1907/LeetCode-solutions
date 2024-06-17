class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = sqrt(c)+1;
        while(l<=r) {
            int lsq = l*l;
            long long rsq = (long)r*(long)r;
            long long sum = lsq + rsq;
            if(sum == c) return true;
            if(sum < c) l++;
            else r--;
        }
        return false;
    }
};