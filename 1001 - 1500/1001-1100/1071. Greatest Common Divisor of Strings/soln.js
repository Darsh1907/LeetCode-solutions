/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
*/

var gcdOfStrings = function(str1, str2) {
    if(str1 + str2 != str2 + str1){
        // If the concatenation of str1 and str2 is not equal to the concatenation of str2 and str1,
        // then there is no common divisor, so return an empty string
        return ""
    }

    // Find the greatest common divisor of the lengths of str1 and str2
    gcd_len = gcd(str1.length, str2.length)
    
    return str1.substring(0, gcd_len)
};

var gcd = function(a,b){
    while(b){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a
}