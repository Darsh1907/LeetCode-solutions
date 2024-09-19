class Solution {
private:
    int solve(vector<int>& obstacles, int currlane, int currpos) {
        //base case
        int n = obstacles.size()-1;
        if(currpos == n) return 0;
        if(obstacles[currpos+1] != currlane) 
            return solve(obstacles, currlane, currpos+1);
        else {
            //sideways jump
            int ans = INT_MAX;
            for(int i=1; i<=3; i++) {
                if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
            }
            return ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2, 0);
    }
};