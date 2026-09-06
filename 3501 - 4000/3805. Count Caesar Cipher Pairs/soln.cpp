class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> freq;
        for (const string& w : words) {
            string key;
            int base = w[0] - 'a';
            for (char c : w) {
                int diff = (c - 'a' - base + 26) % 26;
                key.push_back(diff + 'a');  // encode as char
            }
            freq[key]++;
        }
        long long ans = 0;
        for (auto& [k, c] : freq) {
            ans += c*(c-1)/2;
        }
        return ans;
    }
};