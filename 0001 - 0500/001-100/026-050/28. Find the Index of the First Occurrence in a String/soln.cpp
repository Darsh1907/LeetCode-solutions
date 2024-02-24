class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_size = needle.length();
        int h_size = haystack.size();

        if(n_size > h_size) return -1;

        for(int i=0; (i+n_size-1)<h_size; i++){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i, n_size) == needle) return i;
            }
        }

        return -1;
    }
};