class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        vector<int> result;
        for(int i=0; i<nums1.size(); i++) s1.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++){
            auto itr = s1.find(nums2[i]);
            if(itr!=s1.end()){
                result.push_back(nums2[i]);
                s1.erase(itr);
            }
        }
        return result;
    }
};