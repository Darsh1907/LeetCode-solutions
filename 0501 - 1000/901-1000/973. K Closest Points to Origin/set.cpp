class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        set<pair<float, int>> myset;
        for(int i=0; i<points.size(); i++){
            pair<float, int> temp;
            temp.first = sqrt(abs(points[i][0])*abs(points[i][0]) + abs(points[i][1])*abs(points[i][1]));
            temp.second = i;
            myset.insert(temp);
        }
        vector<vector<int>> result;
        auto itr = myset.begin();
        for(int i=0; i<k; i++){
            result.push_back(points[itr->second]); 
            itr++;
        }
        return result;
    }
};