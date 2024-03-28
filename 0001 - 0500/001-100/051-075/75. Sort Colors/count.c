void sortColors(int* arr, int arrSize) {
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<arrSize; i++){
        if(arr[i]==0) count0++;
        if(arr[i]==1) count1++;
        else count2++;
    }
    for(int i=0; i<count0; i++) arr[i]=0;
    for(int i=count0; i<count0+count1; i++) arr[i]=1;
    for(int i=count0+count1; i<arrSize; i++) arr[i]=2;
}