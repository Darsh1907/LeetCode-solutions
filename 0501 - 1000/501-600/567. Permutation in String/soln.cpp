class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count(26, 0);
        for (int i=0; i<s1.size(); i++) count[s1[i]-'a']++;
        
        vector<int> temp(26, 0);
        for (int i=0; i<s1.size(); i++) temp[s2[i]-'a']++;

        for (int i=s1.size(); i<s2.size(); i++) {
            if (count == temp) return true;
            // Implementation of sliding window
            temp[s2[i-s1.size()] - 'a']--; // remove count of first element that will get removed from the sliding window
            temp[s2[i] - 'a']++; // add count of new element that will come into the sliding window.
        }

        return count == temp; // Check for the last window
    }
};