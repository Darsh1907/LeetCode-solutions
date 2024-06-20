class Solution {
public:
    bool isPossible(vector<int> &position, int k, int mid, int n) {
        int ballCount = 1;
        int lastPos = position[0];
        for(int i=0; i<n; i++ ){
            if(position[i]-lastPos >= mid){
                ballCount++;
                if(ballCount==k) return true;
                lastPos = position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s = 0;
        int size = position.size();
        int e = position[n-1];
        int ans = -1;
        int mid = s + (e-s)/2;
        while(s<=e) {
            if(isPossible(position, m, mid, size)) {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
