class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> sA;
        unordered_set<int> sB;
        vector<int> result;
        int count = 0;
        for(int i=0; i<A.size(); i++){
            if(sB.find(A[i])!=sB.end()) count++;
            sA.insert(A[i]);
            if(sA.find(B[i])!=sA.end()) count++;
            sB.insert(B[i]);
            result.push_back(count);
        }
        return result;
    }
};