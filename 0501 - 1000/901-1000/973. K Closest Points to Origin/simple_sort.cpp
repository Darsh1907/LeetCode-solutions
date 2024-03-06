class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<float, int>> pr; // vector of dist and index
        for(int i=0; i<points.size(); i++){
            pair<float, int> temp;
            temp.first = sqrt(abs(points[i][0])*abs(points[i][0]) + abs(points[i][1])*abs(points[i][1]));
            temp.second = i;
            pr.push_back(temp);
        }
        sort(pr.begin(), pr.end());
        vector<vector<int>> result;
        int i=0;
        while(k--){
            result.push_back(points[pr[i++].second]);
        }
        return result;
    }
};