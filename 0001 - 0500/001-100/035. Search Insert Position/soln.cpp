#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
          int mid = (low + high) / 2;
          if (nums[mid]==target) return mid;
          else if (nums[mid] < target) low = mid + 1;
          else high = mid - 1;
        }
        return low;
    }
};

int main() {
    // Example usage
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    Solution solution;
    int index = solution.searchInsert(nums, target);

    cout << "Insert position: " << index << endl;

    return 0;
}
