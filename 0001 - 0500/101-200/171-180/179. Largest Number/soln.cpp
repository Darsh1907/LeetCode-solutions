bool compare(string& a, string& b) {
    if(a+b > b+a) return true;
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums2;
        for(int num: nums) nums2.push_back(to_string(num));
        sort(nums2.begin(), nums2.end(), compare);
        string res;
        for(string& str: nums2) res += str;
        if(res[0]=='0') return "0";
        return res;
    }
};