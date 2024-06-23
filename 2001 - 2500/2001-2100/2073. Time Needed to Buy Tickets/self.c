int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int result=0;
    while(tickets[k]>0) {
        for(int i=0; i<ticketsSize; i++) {
            if(tickets[i]) {
                tickets[i]--;
                result++;
                if(tickets[k]==0) break;
            }
        }
    }
    return result;
}