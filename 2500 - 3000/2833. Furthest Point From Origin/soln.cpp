class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount = 0;
        int rcount =0;
        int scount = 0;
        for(int i=0; i<moves.size(); i++) {
            if(moves[i]=='L') lcount++;
            if(moves[i]=='R') rcount++;
            if(moves[i]=='_') scount++;
        }
        if(lcount>=rcount) return (scount+lcount-rcount);
        return (scount+rcount-lcount);
    }
};