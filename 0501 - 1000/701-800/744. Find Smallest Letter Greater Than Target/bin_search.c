char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int res_ind = 0;
    int s = 0, e = lettersSize-1, m;
    while(s <= e) {
        m = s+(e-s)/2;
        if(letters[m] > target){
            res_ind = m;
            e = m-1;
        }
        else s = m+1;
    }
    return letters[res_ind];
}