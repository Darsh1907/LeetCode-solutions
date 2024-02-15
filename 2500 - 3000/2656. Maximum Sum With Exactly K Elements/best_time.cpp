class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi=0;
        for(auto i:nums){
            if(maxi<i) maxi=i;
        }
        int ans=0;
        for(auto i=0;i<k;++i){
            ans += maxi;
            maxi++;
        }
        return ans;
    }
};