class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> points(100, false);
        for(int i=0; i<nums.size(); i++){
            for(int j=nums[i][0]; j<=nums[i][1]; j++) 
                points[j-1] = true;
        }
        int count = 0;
        for(int i=0; i<points.size(); i++) 
            if(points[i]==true) count++;
        return count;
    }
};