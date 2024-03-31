class Solution {
private:
    long long int max_element(unordered_map<int, long long int>& umap){
        long long int max_ele = umap.begin()->first;
        for(auto i=umap.begin(); i!=umap.end(); i++) {
            if(i->second > umap[max_ele]) max_ele = i->first;
        }
        return max_ele;
    }
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> result(nums.size());
        unordered_map<int, long long int> umap;
        long long int max_ele = nums[0];
        for(int i=0; i<nums.size(); i++) {
            umap[nums[i]] += freq[i];
            if(nums[i]==max_ele && freq[i]<0) max_ele = max_element(umap);
            else if(umap[nums[i]]>umap[max_ele]) max_ele = nums[i];
            result[i] = umap[max_ele];
        }
        return result;
    }
};