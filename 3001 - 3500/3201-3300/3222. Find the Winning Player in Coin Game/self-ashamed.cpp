class Solution {
public:
    string losingPlayer(int x, int y) {
        bool isAlice = false;
        y = y/4;
        while(1) {
            isAlice = !isAlice;
            if(x==0 || y==0) break;
            x--;
            y--;
        }
        if(isAlice) return "Bob";
        return "Alice";
    }
};