class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            vector<vector<int>> result;
            result.push_back(newInterval);
            return result;
        }
        vector<vector<int>> result;
        int i=0;
        if(intervals[0][0]>newInterval[0]) result.push_back(newInterval);
        else {
            result.push_back(intervals[0]);
            i++;
        }
        for(; i<intervals.size() && intervals[i][0]<newInterval[0]; i++) {
            if(intervals[i][0]<=result.back()[1]) result.back()[1] = max(result.back()[1], intervals[i][1]);
            else result.push_back(intervals[i]);
        }
        if(newInterval[0]<=result.back()[1]) result.back()[1] = max(result.back()[1], newInterval[1]);
        else result.push_back(newInterval);
        for(; i<intervals.size(); i++) {
            if(intervals[i][0]<=result.back()[1]) result.back()[1] = max(result.back()[1], intervals[i][1]);
            else result.push_back(intervals[i]);
        }
        return result;
    }
};