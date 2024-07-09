int max(int a, int b) {if(a>=b) return a; return b;}

double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    // initialize values for first customer.
    double wtime = customers[0][1];
    int currtime = customers[0][0] + customers[0][1];
    // from second onwards
    for (int i=1; i<customersSize; i++) {
        int arrive = customers[i][0];
        int start_cook = max(arrive, currtime);
        int end_time = start_cook + customers[i][1];
        currtime = end_time;
        wtime += end_time - arrive;
    }
    return wtime/customersSize;
}