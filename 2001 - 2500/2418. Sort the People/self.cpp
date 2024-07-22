class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<pair<int, string>> temp; 
        for(int i=0; i<n; i++) temp.push_back({heights[i], names[i]});
        sort(temp.begin(), temp.end());
        vector<string> res;
        for(int i=n-1; i>=0; i--) res.push_back(temp[i].second);
        return res;
    }
};