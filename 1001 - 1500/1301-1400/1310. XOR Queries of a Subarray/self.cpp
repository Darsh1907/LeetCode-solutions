class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref_xor(n);
        pref_xor[0] = arr[0];
        for(int i=1; i<n; i++) pref_xor[i] = pref_xor[i-1] ^ arr[i];
        vector<int> res;
        for(vector<int>& query: queries) {
            int start = query[0];
            int end = query[1];
            if(start==0) res.push_back(pref_xor[end]);
            else res.push_back(pref_xor[end]^pref_xor[start-1]);
        }
        return res;
    }
};