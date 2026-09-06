class Solution {
public:
    int residuePrefixes(string s) {
        vector<int> freq(26, 0);
        int distinct = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if(freq[idx] == 0) {
                distinct++;
            }
            freq[idx]++;
            int len = i + 1;
            if(distinct == len % 3) {
                count++;
            }
        }
        return count;
    }
};