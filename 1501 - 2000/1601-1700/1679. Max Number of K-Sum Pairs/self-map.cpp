class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // number -> frequency
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            auto ptr = umap.find(k-nums[i]);
            if(ptr==umap.end() || ptr->second==0) umap[nums[i]]++;
            else {
                ptr->second--;
                count++;
            }
        }
        return count;
    }
};