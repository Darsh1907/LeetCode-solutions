class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> s;
        for(int i=0; i<points.size(); i++) s.insert(points[i][0]);
        vector<int> xpoints;
        for(auto i=s.begin(); i!=s.end(); i++) xpoints.push_back(*i);
        for(int i=1; i<xpoints.size(); i++) {
            if(abs(xpoints[i]-xpoints[i-1])<=w) {
                xpoints.erase(xpoints.begin()+i);
                i--;
            }
        }
        return xpoints.size();
    }
};