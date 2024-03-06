class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> mp;
        // Count the frequency of each word
        for(int i=0; i<words.size(); i++) mp[words[i]]++;
        // Convert the map to a vector of pairs
        vector<pair<int, string>> v;
        for(auto entry: mp) v.push_back({entry.second, entry.first});
        // Sorting the vector based on frequency and lexicographical order
        sort(v.begin(), v.end(), [&](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) 
                return a.first > b.first; // Sort by frequency (decreasing order)
            else
                return a.second < b.second; // If frequencies are same, sort lexicographically (increasing order)
        });
        // Push the top k frequent words into the answer vector
        for(int i = 0; i<k; i++) ans.push_back(v[i].second);
        return ans;
    }
};