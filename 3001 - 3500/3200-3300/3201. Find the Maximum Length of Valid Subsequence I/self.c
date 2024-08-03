int max(int a, int b, int c) {
    if(a >= b) {
        if(a >= c) return a;
        return c;
    }
    else {
        if(b >= c) return b;
        return c;
    }
}

int evenOdd(int* nums, int numsSize) {
    int cnt = 0;
    bool takeEven = true;
    for(int i=0; i<numsSize; i++) {
        if(takeEven && nums[i]%2==0) {
            cnt++;
            takeEven = !takeEven;
        }
        else if(!takeEven && nums[i]%2==1){
            cnt++;
            takeEven = !takeEven;
        }
    }
    return cnt;
}

int oddEven(int* nums, int numsSize) {
    int cnt = 0;
    bool takeOdd = true;
    for(int i=0; i<numsSize; i++) {
        if(takeOdd && nums[i]%2==1) {
            cnt++;
            takeOdd = !takeOdd;
        }
        else if(!takeOdd && nums[i]%2==0){
            cnt++;
            takeOdd = !takeOdd;
        }
    }
    return cnt;
}

int both(int* nums, int numsSize) {
    int evenCnt = 0;
    int oddCnt = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i]%2==0) evenCnt++;
        else if(nums[i]%2==1) oddCnt++;
    }
    if(evenCnt > oddCnt) return evenCnt;
    return oddCnt;
}

int maximumLength(int* nums, int numsSize) {
    return max(evenOdd(nums, numsSize), oddEven(nums, numsSize), both(nums, numsSize));
}