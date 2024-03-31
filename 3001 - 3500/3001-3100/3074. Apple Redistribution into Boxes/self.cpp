class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for(int i=0; i<apple.size(); i++) total += apple[i];
        sort(capacity.begin(), capacity.end());
        int result = 0;
        for(int i=capacity.size()-1; i>=0 && total>0; i--){
            total -= capacity[i];
            result++;
        }
        return result;
    }
};