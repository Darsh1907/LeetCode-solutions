// simple optimization to the self.cpp

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> mymap; // this is store the frequency of eacy number in the array.
        unordered_map<int, int> umap; // this is to store the no. of numbers lesser than some particular number
        for(int i=0; i<nums.size(); i++) mymap[nums[i]]++;
        for(int i=0; i<nums.size(); i++){
            if(umap.find(nums[i]) == umap.end()){
                int count = 0;
                for(auto j=mymap.begin(); j->first!=nums[i]; j++){
                    count = count + j->second;
                }
                umap[nums[i]] = count;
                nums[i] = count;
            }
            else nums[i] = umap[nums[i]];
        }
        return nums;
    }
};