#include <unordered_set>
#include <string>
using namespace std;


class Solution {
public:
    int passwordStrength(string password) {
        int score = 0;
        unordered_set<char> uset;
        for(char ch: password) uset.insert(ch);
        for(char ch: uset) {
            if(isLowerCase(ch)) score++;
            else if(isUpperCase(ch)) score = score+2;
            else if(isDigit(ch)) score=score+3;
            else score = score+5;
        }
        return score;
    }
    bool isLowerCase(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    bool isUpperCase(char ch){
        return ch >= 'A' && ch <= 'Z' ;
    }
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
};