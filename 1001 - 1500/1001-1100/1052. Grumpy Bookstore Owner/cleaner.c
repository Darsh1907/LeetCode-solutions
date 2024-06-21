int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int initialsatisfied=0;
    int latersatisfied=0;
    int maxlatersatisfied=0;

    for(int i=0;i<customersSize;++i){
        if(grumpy[i]==0) initialsatisfied+=customers[i];
    }

    for(int i=0;i<minutes;++i){
        if(grumpy[i]==1) latersatisfied+=customers[i];
    }
    maxlatersatisfied=latersatisfied;

    for(int i=minutes;i<customersSize;++i){
        if(grumpy[i]==1) latersatisfied+=customers[i];
        if(grumpy[i-minutes]==1) latersatisfied-=customers[i-minutes];
        if(latersatisfied>maxlatersatisfied) maxlatersatisfied=latersatisfied;
    }
    return initialsatisfied+maxlatersatisfied;
}