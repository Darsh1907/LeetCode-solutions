class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt=0;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (nums[j]-nums[i]==k) cnt++;
                else if (nums[j]-nums[i] > k) break;
            }
        }
        return cnt;
    }
};