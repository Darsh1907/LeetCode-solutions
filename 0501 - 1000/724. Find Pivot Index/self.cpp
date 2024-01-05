// This code gives runtime error for some unkown reason.

#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int index = 0;
        int l_sum = 0;
        int r_sum = 0;
        for (int i=1; i<nums.size(); i++) {
            r_sum = r_sum + nums[i];
        }
        if (l_sum == r_sum) return 0;
        while ((l_sum != r_sum) && (index < nums.size())) {
            l_sum = l_sum + nums[index];
            index++;
            r_sum = r_sum - nums[index];
        }
        if (l_sum == r_sum) return index;
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