class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> interval = points[0];
        int ans = 1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=interval[1]){
                interval[0]=interval[1];
                interval[1]=min(points[i][1], interval[1]);
            }
            else {
                interval = points[i];
                ans++;
            }
        }
        return ans;
    }
};