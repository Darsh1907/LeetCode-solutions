int max(int a, int b){
    if(a>=b) return a;
    return b;
}

int leastInterval(char* tasks, int tasksSize, int n) {
    if(n==0) return tasksSize;
    int freqs[26] = {0};
    int max_freq = 0;
    int num_of_max = 0;
    for(int i=0; i<tasksSize; i++){
        freqs[tasks[i]-'A']++;
        if(freqs[tasks[i]-'A'] > max_freq){
            max_freq = freqs[tasks[i]-'A'];
            num_of_max = 1;
        }
        else if(freqs[tasks[i]-'A']==max_freq) num_of_max++;
    }
    return max((max_freq-1)*(n+1)+num_of_max, tasksSize);
}