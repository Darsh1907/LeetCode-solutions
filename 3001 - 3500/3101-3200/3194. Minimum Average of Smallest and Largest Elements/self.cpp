class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int upto = nums.size()/2;
        double minAvg = 100;
        for(int i=0; i<upto; i++) {
            double avg = (double)(nums[i] + nums[nums.size()-i-1])/2;
            if(avg<minAvg) minAvg = avg;
        }
        return minAvg;
    }
};