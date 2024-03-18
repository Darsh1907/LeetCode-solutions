class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> interval = points[0];
        int ans = 1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=interval[1]){
                vector<int> temp(2);
                temp[0]=interval[1];
                temp[1]=min(points[i][1], interval[1]);
                interval = temp;
            }
            else {
                interval = points[i];
                ans++;
            }
        }
        return ans;
    }
};