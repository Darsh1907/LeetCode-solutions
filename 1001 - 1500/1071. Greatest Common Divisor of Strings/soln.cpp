class Solution {
public:

    int gcd(int a, int b){
        // Euclidean algorithm to find the greatest common divisor
        while(b){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
            // If the concatenation of str1 and str2 is not equal to the concatenation of str2 and str1,
            // then there is no common divisor, so return an empty string
            return "";

        // Find the greatest common divisor of the lengths of str1 and str2
        int gcd_len = gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_len);
    }
};