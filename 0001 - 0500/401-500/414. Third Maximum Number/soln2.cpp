class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        stack<int> s;
        sort(nums.begin(), nums.end());
        s.push(nums[nums.size() - 1]);
        if (nums.size() >= 3) {
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] == s.top()) {
                    s.pop();
                    s.push(nums[i]);
                }
                else s.push(nums[i]);
                if (s.size() == 3) return s.top();
            }
        }
        else return nums[nums.size() - 1];
        return nums[nums.size()-1]; 
    }
};