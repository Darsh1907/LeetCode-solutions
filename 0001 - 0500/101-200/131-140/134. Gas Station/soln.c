// References:
// https://www.youtube.com/watch?v=_gJ3to4RyeQ&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=67

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int deficit=0, balance=0, start=0;
    for(int i=0; i<costSize; i++){
        balance += gas[i] - cost[i];
        if(balance < 0) {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    if(deficit + balance >= 0) return start;
    return -1;
}