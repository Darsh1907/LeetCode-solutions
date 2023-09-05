class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128, 0);
        int ans = 0;
        int size = 0;
        int i = 0;
        int j = 0;
        while(s[j] != '\0'){
            if(count[s[j]] == 0){
                size++;
                count[s[j]] += 1;
                if( size > ans)
                    ans = size;
            }
            else if(count[s[j]] == 1){
                count[s[j]] += 1;
                while(s[i] != s[j]){
                    count[s[i]] -= 1;
                    size--;
                    i++;
                }
                count[s[i]] -= 1;
                i++;
            }
            j++;
        }
        return ans;
    }
};