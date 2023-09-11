bool validMountainArray(int* arr, int arrSize){
    if(arrSize<3 || arr[0]>arr[1]) return false;
    bool increase=true; 
    int i=0;
    while(i<arrSize-1) {
        if(arr[i]==arr[i+1]) return false;
        if(increase) {
            if(arr[i]>arr[i+1]) increase=false;
        }
        else if(arr[i]<arr[i+1]) return false;
        i++;
    }
    if(increase) return false;
    return true;
}