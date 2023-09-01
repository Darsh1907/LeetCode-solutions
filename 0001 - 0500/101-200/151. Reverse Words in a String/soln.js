/**
 * @param {string} s
 * @return {string}
*/

var reverseWords = function(s) {
    // Remove leading and trailing spaces
    s = s.trim();
    // Split the string into an array of words
    var words = s.split(/\s+/);
    // Reverse the array of words and join them back into a string
    var reversed = words.reverse().join(' ');
    
    return reversed;
};