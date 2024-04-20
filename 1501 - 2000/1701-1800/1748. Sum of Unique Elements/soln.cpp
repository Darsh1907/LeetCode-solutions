class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> umap;
        int result = 0;

        for(int i=0; i<nums.size(); i++) umap[nums[i]]++;

        unordered_map<int, int>::iterator itr;
        for(itr = umap.begin(); itr!=umap.end(); itr++){
            if(itr->second == 1) result=result+(itr->first);
        }
        
        return result;
    }
};