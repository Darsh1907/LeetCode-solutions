int furthestDistanceFromOrigin(char * moves){
    int lcount = 0;
    int rcount = 0;
    int scount = 0;
    int size = strlen(moves);
    for(int i=0; i<size; i++) {
        if(moves[i]=='L') lcount++;
        else if(moves[i]=='R') rcount++;
        else scount++;
    }
    if(lcount>=rcount) return (scount+lcount-rcount);
    return (scount+rcount-lcount);
}