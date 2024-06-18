class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxDiff = 0;
        int diff;
        for(int i=1; i<points.size(); i++) {
            diff = points[i][0] - points[i-1][0];
            if(diff > maxDiff) maxDiff = diff;
        }
        return maxDiff;
    }
};