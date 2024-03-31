int max(int a, int b) {return (a > b) ? a : b;}

int encrypt(int num) {
    int maxd = 0, len = 0;
    while(num != 0) {
        maxd = max(maxd, (num % 10));
        len++;
        num /= 10;
    }
    int new_num = 0;
    while(len--) new_num = new_num * 10 + maxd;
    return new_num;
}

int sumOfEncryptedInt(int* nums, int numsSize) {
    int ans = 0;
    for(int i=0; i<numsSize; i++) ans = ans + encrypt(nums[i]);
    return ans;
}