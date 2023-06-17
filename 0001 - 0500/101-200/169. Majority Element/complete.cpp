#include <vector>
#include <iostream>

using namespace std;

// The basic idea behind this algorithm is to cancel out pairs of different elements.
// Since the majority element appears more than ⌊n/2⌋ times, even after canceling out
// all the pairs of different elements, the majority element will still be left.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==res) count++;
            if(nums[i]!=res) count--;
            if(count<0) res=nums[i];
        }
        return res;
    }
};

int main() {
    // Example usage
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution solution;
    int majority = solution.majorityElement(nums);
    std::cout << "Majority element: " << majority << std::endl;
    return 0;
}