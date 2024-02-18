class Solution {
public:
    int findDuplicate(vector<int>& nums) { 
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++){
            umap[nums[i]]++;
            if(umap[nums[i]]==2) return nums[i];
        }
        return -1;
    }
};