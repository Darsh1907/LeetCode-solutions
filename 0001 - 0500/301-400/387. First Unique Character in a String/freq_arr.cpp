class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(auto ch : s) freq[ch-'a']++;
        for(auto ch : s) if(freq[ch-'a'] == 1) return i;
        return -1;
    }
};