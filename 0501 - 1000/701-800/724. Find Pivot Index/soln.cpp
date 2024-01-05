#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int n =nums.size();
        int totalSum=0;
        int leftSum=0;
        for(int i=0;i<n;i++) totalSum+=nums[i];
        for(int i=0;i<n;i++){
            int rightSum=totalSum-nums[i]-leftSum;
            if(leftSum==rightSum) return i;
            else leftSum+=nums[i];
        }
        return -1;
    }
};

int main() {
    Solution solution;
    // Example usage
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = solution.pivotIndex(nums);
    std::cout << "Pivot index: " << result << std::endl;
    return 0;
}