class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        const int n = arr.size();
        vector<string> r(n);
        for (int i = 0; i < n; ++i) {
            for (int len = 1; r[i].empty() && len <= arr[i].length(); ++len) {
                for (int b = 0; b + len <= arr[i].length(); ++b) {
                    const string s = arr[i].substr(b, len);
                    bool found = false;
                    for (int j = 0; !found && j < n; ++j) {
                        found = j != i && arr[j].find(s) != string::npos;
                    }
                    if (!found && (r[i].empty() || r[i] > s)) {
                        r[i] = s;
                    }
                }
            }
        }
        return r;
    }
};