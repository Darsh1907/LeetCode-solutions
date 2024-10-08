#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> newvec;
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                newvec.push_back(sum);
            }
        }
        sort(newvec.begin(), newvec.end());
        int ans = 0;
        for(int i=left-1; i<right; i++) ans = (ans + newvec[i])%MOD;
        return ans;
    }
};