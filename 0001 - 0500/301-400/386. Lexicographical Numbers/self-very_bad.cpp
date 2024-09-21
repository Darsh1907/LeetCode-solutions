class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> nums;
        for(int i=1; i<=n; i++) nums.push_back(to_string(i));
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(string& str: nums) ans.push_back(stoi(str));
        return ans;
    }
};