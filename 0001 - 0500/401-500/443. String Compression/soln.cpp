class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0; // For traversing entire array
        int ansIndex = 0; // For inserting counts in the same input array
        int n = chars.size();
        while(i<n) {
            int j = i+1;
            while(j<n && chars[i]==chars[j]) j++; // j will point to the next character or to the end of the vector
            chars[ansIndex++] = chars[i];
            int count = j-i;
            if(count>1) {
                string cnt = to_string(count); // converting count to string
                for(int i=0; i<cnt.size(); i++){ // if string is more than 1 digit, add individual digits
                    chars[ansIndex++] = cnt[i];
                }
            }
            i = j; 
        }
        return ansIndex;
    }
};