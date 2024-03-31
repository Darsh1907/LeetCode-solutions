class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        // Make frequency maps for both arrays.
        for(int i=0; i<nums1.size(); i++) mp1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) mp2[nums2[i]]++;
        int toDelete1 = nums1.size()/2, toDelete2 = nums2.size()/2;
        // Remove as many duplicates as possible
        for(auto i=mp1.begin(); i!=mp1.end(); i++) {
            if(i->second > 1) {
                toDelete1 -= (i->second - 1);
                i->second = 1;
            }
        }
        for(auto i=mp2.begin(); i!=mp2.end(); i++) {
            if(i->second > 1) {
                toDelete2 -= (i->second - 1);
                i->second = 1;
            }
        }
        // If removing duplicates satisfies the number of removals expected than return
        if(toDelete1<=0 && toDelete2<=0){
            mp1.insert(mp2.begin(), mp2.end());
            return mp1.size();
        }
        // If not, merge the maps. And again do the same thing i.e, remove duplicates.
        for(auto i=mp2.begin(); i!=mp2.end(); i++) mp1[i->first]++;
        if(toDelete1<=0 || toDelete2<=0) toDelete1 = max(toDelete1, toDelete2);
        else toDelete1 = toDelete1 + toDelete2;
        for(auto i=mp1.begin(); i!=mp1.end(); i++) {
            if(i->second > 1) {
                toDelete1 = toDelete1 - 1;
                i->second = 1;
            }
        }
        // If removing duplicates from mergind, satisfies the removal condition then return
        if(toDelete1<=0) return mp1.size();
        // Else,...
        return mp1.size()-toDelete1;
    }
};