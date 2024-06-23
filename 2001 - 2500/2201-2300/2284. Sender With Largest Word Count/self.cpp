class Solution {
public:
    int wordCount(string& str){
        int count = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i]==' ') count++;
        }
        return count+1;
    }

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mp;
        for(int i=0; i<senders.size(); i++){
            mp[senders[i]] += wordCount(messages[i]);
        }
        vector<pair<int, string>> v;
        for(auto entry: mp) v.push_back({entry.second, entry.first});
        // Sorting the vector based on frequency and lexicographical order
        sort(v.begin(), v.end(), [&](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) 
                return a.first > b.first; // Sort by frequency (decreasing order)
            else
                return a.second > b.second; // If frequencies are same, sort lexicographically (decreasing order)
        });
        return v[0].second;
    }
};