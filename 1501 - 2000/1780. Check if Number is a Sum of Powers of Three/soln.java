// The number can not be represented as a sum of powers of 3 
// if it's ternary presentation has a 2 in it

class Solution {
    public boolean checkPowersOfThree(int n) {
        while(n > 0) {
            if(n%3==2) return false;
            n = n/3;
        }
        return true;
    }
}