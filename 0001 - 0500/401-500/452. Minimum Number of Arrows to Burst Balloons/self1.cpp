class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> merged;
        merged.push_back(points[0]);
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=merged.back()[1]){
                vector<int> temp(2);
                temp[0]=merged.back()[1];
                temp[1]=min(points[i][1], merged.back()[1]);
                merged.back() = temp;
            }
            else merged.push_back(points[i]);
        }
        return merged.size();
    }
};