class Solution {
public:
    int minimumPushes(string& word) {
        // freq array to keep track of frequencies.
        vector<int> freq(26, 0);
        for(char c: word) freq[c-'a']++;
        // sorting freq in decreasing order
        sort(freq.begin(), freq.end(), greater<int>());
        // for higher frequency element, assign the lowest possible push.
        int push=1, ans=0;
        for(int i=0; i<26 && freq[i]!=0; i++){
            if(i>=8 && i%8==0) push++;
            ans += freq[i]*push;    
        }
        return ans;
    }
};