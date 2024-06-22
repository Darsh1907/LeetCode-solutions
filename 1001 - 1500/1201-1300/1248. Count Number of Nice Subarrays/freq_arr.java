class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int i = 0; i < n; i++) {
            t += nums[i] & 1;
            if(t-k >= 0) ans+=cnt[t-k];
            cnt[t]++;
        }
        return ans;
    }
}