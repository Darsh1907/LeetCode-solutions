class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> s_indices;
        for (int i=0; i<s.size(); i++) s_indices[s[i]] = i;
        int difference = 0;
        for (int i=0; i<t.size(); i++) difference += abs(s_indices[t[i]]-i);
        return difference;
    }
};