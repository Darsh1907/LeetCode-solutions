int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int total = 0;
    // Calculate the initial total of satisfied customers
    for(int i=0; i<customersSize; i++) {
        if(!grumpy[i]) total += customers[i];
    }
    int j=0, i=0;
    int tempSum = 0;
    while(j-i != minutes) {
        if(grumpy[j]==1) tempSum += customers[j];
        j++;
    }
    int maxSum = tempSum;
    while(j<customersSize) {
        if(grumpy[j]) tempSum += customers[j];
        if(grumpy[i]) tempSum -= customers[i];
        i++;
        j++;
        if(tempSum > maxSum) maxSum=tempSum;
    }
    return (total + maxSum);
}