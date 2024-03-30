class Solution {
private:
    void createLeftMax(vector<int>& left_max, vector<int>& height, int n){
        left_max[0]=0;
        for(int i=1; i<n; i++){
            left_max[i] = max(left_max[i-1], height[i-1]);
        }
    }
    void createRightMax(vector<int>& right_max, vector<int>& height, int n){
        right_max[n-1]=0;
        for(int i=n-2; i>=0; i--){
            right_max[i] = max(right_max[i+1], height[i+1]);
        }
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        createLeftMax(left_max, height, n);
        createRightMax(right_max, height, n);
        int water = 0;
        for(int i=0; i<n; i++){
            int temp = min(right_max[i], left_max[i]) - height[i];
            if(temp>0) water += temp;
        }
        return water;
    }
};