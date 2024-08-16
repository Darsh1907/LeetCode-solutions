class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int, int> minn {INT_MAX, -1};
        pair<int, int> sec_min = {INT_MAX, -1};
        pair<int, int> maxx = {INT_MIN, -1};
        pair<int, int> sec_max = {INT_MIN, -1};
        for(int i=0; i<arrays.size(); i++) {
            int minele = arrays[i][0];
            int maxele = arrays[i].back();
            if(minn.first > minele) {
                sec_min = minn;
                minn = {minele, i};
            }
            else if(sec_min.first > minele) sec_min = {minele, i};
            if(maxx.first < maxele) {
                sec_max = maxx;
                maxx = {maxele, i};
            }
            else if(sec_max.first < maxele) sec_max = {maxele, i};
        }
        if(minn.second == maxx.second) {
            return max(sec_max.first - minn.first, maxx.first - sec_min.first);
        }
        return (maxx.first - minn.first);
    }
};