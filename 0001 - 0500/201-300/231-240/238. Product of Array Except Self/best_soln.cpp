class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), total = 1;
        vector<int> result(n, 1);
        //left side
        for(int i=1; i<n; i++) result[i] = result[i-1]*nums[i-1];
        //right side
        int right = 1;
        for(int i=n-2; i>=0; i--){
            right = right * nums[i+1];
            result[i] = result[i] * right;
        }
        return result;
    }
};