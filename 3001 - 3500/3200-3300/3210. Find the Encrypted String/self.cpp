class Solution {
public:
    string getEncryptedString(string s, int k) {
        int size = s.size();
        k = k % size;
        string s_double = s + s; 
        for(int i=0; i<size; i++) s[i] = s_double[i+k];
        return s;
    }
};