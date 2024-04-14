class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int count=0;
        int i=0;
        int j=1;
        int n=points.size();
        while(i<n) {
            while(j<n && points[j][0]-points[i][0]<=w) j++;
            count++;
            i=j;
        }
        return count;
    }
};