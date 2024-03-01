class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        vector<int> temp1;
        vector<int> temp2;
        vector<vector<int>> result;
        for(int i=0; i<nums1.size(); i++) s1.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++) s2.insert(nums2[i]);
        for(auto i=s1.begin(); i!=s1.end(); i++) {
            if(s2.find(*i)==s2.end()) temp1.push_back(*i);
        }
        result.push_back(temp1);
        for(auto i=s2.begin(); i!=s2.end(); i++) {
            if(s1.find(*i)==s1.end()) temp2.push_back(*i);
        }
        result.push_back(temp2);
        return result;
    }
};