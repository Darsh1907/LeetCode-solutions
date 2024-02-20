class Solution {
public:
    bool detectCapitalUse(string word) {
        int size = word.size();
        if(size==1) return true;

        if(word[0]>'Z'){ // if first letter is small
            for(int i=1; i<size; i++){
                if(word[i]<'a') return false; // every other letter should also be small
            }
            return true;
        }

        if(word[1]>'Z'){ // if first letter is captial and second is small
            for(int i=2; i<size; i++){
                if(word[i]<'a') return false; // every other letter should also be small
            }
            return true;
        }

        for(int i=2; i<size; i++){ // if first letter is capital and second is also capital
            if(word[i]>'Z') return false;
        }

        return true;
    }
};