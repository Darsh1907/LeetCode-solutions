// Refer: https://www.youtube.com/watch?v=OKcrLfR-8mE

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // map to store remainder and index position
        umap[0] = -1; // this handles cases where the subarray starts from index 0
        int curr_sum = 0;
        for(int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            int mod = curr_sum % k;
            if(mod < 0) mod += k; // handle negative mod results
            if(umap.find(mod) != umap.end()) {
                if(i - umap[mod] > 1) return true;
            }
            else umap[mod] = i;
        }
        return false;
    }
};