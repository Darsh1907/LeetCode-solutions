int maxFrequencyElements(int* nums, int numsSize) {
    int freq[101] = {0};
    int result = 0;
    int max_freq = 0;
    for(int i = 0; i<numsSize; i++){
        freq[nums[i]]++;
        if(freq[nums[i]] > max_freq){
            max_freq = freq[nums[i]];
            result = max_freq;
        }
        else if(freq[nums[i]] == max_freq) result = result + max_freq;
    }
    return result;
}