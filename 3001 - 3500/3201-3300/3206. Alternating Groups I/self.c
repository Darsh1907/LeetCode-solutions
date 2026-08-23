int numberOfAlternatingGroups(int* colors, int colorsSize) {
    int count = 0;
    int n = colorsSize;
    if(colors[n-1] != colors[0] && colors[0] != colors[1]) count++;
    for(int i=1; i<n-1; i++) {
        if(colors[i-1]!=colors[i] && colors[i]!=colors[i+1]) count++;
    }
    if(colors[n-2]!=colors[n-1] && colors[n-1]!=colors[0]) count++;
    return count;
}