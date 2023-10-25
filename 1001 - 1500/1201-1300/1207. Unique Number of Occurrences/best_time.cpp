class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        unordered_map<short, short> mp;
        for(int i = 0; i < a.size(); i++)
            mp[a[i]]++;
        set<short> st;
        for(auto i: mp)
            st.insert(i.second);
        return st.size() == mp.size();
    }
};