class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0, y=0;
        for(string str: commands) {
            if(str[0]=='U') x--;
            else if(str[0]=='R') y++;
            else if(str[0]=='D') x++;
            else y--;
        }
        return (x*n)+y;
    }
};