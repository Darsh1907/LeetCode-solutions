class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> umap;
        umap[0] = -1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) sum += 1;
            else sum -= 1;
            if(umap.find(sum)!=umap.end()) result = max(result, i-(umap[sum])); 
            else umap[sum] = i;
        }
        return result;
    }
};