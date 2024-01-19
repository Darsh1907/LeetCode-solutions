class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        int i=0;
        while(result.size() < n){
            if(arr[i]!=0) result.push_back(arr[i]);
            else {
                result.push_back(0);
                result.push_back(0);
            }
            i++;
        }
        if(result.size()!=n) result.pop_back();
        arr = result;    
    }
};