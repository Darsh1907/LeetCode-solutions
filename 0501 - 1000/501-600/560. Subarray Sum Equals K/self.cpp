class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int curr_sum = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            curr_sum = curr_sum + nums[i];
            if(curr_sum == k) res++;
            if(umap.find(curr_sum-k)!=umap.end()) res = res + umap[curr_sum-k];
            umap[curr_sum]++;
        }
        return res;
    }
};