class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        int maxVal = arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxVal<arr[i+1]){
                maxVal=arr[i+1];
            }
            ans[i]=maxVal;
        }
        ans[n-1] = -1;
        return ans;
        
    }
};